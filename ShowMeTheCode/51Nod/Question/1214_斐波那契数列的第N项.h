#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*     1214题：斐波那契数列的第N项
斐波那契数列的定义如下：
F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) (n >= 2)

给出n，求F(n)，由于结果很大，输出F(n) % 1000000009的结果即可。
Input
输入1个数n(1 <= n <= 10^18)。
Output
输出F(n) % 1000000009的结果。

题目网址：http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1242
*/

typedef long long ll;
const ll m_remainder = 1000000009;

void mul(ll c[2][2], ll a[2][2], ll b[2][2]){
	ll t[4];
	t[0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
	t[1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
	t[2] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
	t[3] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
	c[0][0] = t[0] % m_remainder;
	c[0][1] = t[1] % m_remainder;
	c[1][0] = t[2] % m_remainder;
	c[1][1] = t[3] % m_remainder;
}

void pow(ll s[2][2], ll a[2][2], ll n){
	while(n > 0){
		if(n&1) mul(s, s, a);
		mul(a, a, a);
		n >>= 1;
	}
}

ll fibonacci(ll  n) {
	if(n == 0) return 0;
	if(n == 1 || n == 2) return 1;

	ll a[2][2] = { {1, 1}, {1, 0} };
	ll s[2][2] = { {1, 0}, {0, 1} };
	pow(s, a, n-2);
	return s[0][0] + s[0][1];
}

int main_1214_AC() {		// 用来通过AC测试的 main() 函数
	long long n;
	long long sum;
	cin>>n;

	sum = fibonacci(n);
	sum %=m_remainder;  
	cout<<sum;
	return 0;
}

int main_1214_Test() {		// 用来输出测试的 函数。

	long long n;
	long long sum;

#if 0
	n = 5024295251;
	long long i = n;
	while (i <= n)
	{
		sum = fibonacci(i);
		sum %= remainder;  
		cout << sum << "%n";
		++i;
	}
#else
	while (1) {
		cin >> n;
		sum = fibonacci(n);
		sum %= m_remainder;  
		cout << "f(" << n << ") = "<< sum << endl ;			// f(n) = sum
	}
	

#endif
	return 0;
}

