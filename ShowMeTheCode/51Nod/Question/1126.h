#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*     1126题：求递推序列的第N项

有一个序列是这样定义的：f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
给出A，B和N，求f(n)的值。
Input
输入3个数：A,B,N。数字之间用空格分割。(-10000 <= A, B <= 10000, 1 <= N <= 10^9)
Output
输出f(n)的值。

题目网址：http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1126
*/

#if 0		// 系数矩阵如下：【自己在纸上推，很容易就出来了】
[A, B]
[1, 0]
#endif

typedef long long ll;
const ll m_remainder = 7;


#if 0		// 矩阵解法 - 做不出来,因为有负数, 这个  (A - B)%7  如何使用 分配率 ？
void mul(ll c[2][2], ll a[2][2], ll b[2][2]){
	ll t[4];
	t[0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
	t[1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
	t[2] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
	t[3] = a[1][0]*b[0][1] + a[1][1]*b[1][1];

	c[0][0] = t[0] mod m_remainder;
	c[0][1] = t[1] mod m_remainder;
	c[1][0] = t[2] mod m_remainder;
	c[1][1] = t[3] mod m_remainder;
#if 0
	if (rem == true)
	{
		c[0][0] = t[0] % m_remainder;
		c[0][1] = t[1] % m_remainder;
		c[1][0] = t[2] % m_remainder;
		c[1][1] = t[3] % m_remainder;
	} else {
		c[0][0] = t[0];
		c[0][1] = t[1];
		c[1][0] = t[2];
		c[1][1] = t[3];
	}
#endif	
}

void pow(ll s[2][2], ll a[2][2], ll n){
	while(n > 0){
		if(n&1) mul(s, s, a);
		mul(a, a, a);
		n >>= 1;
	}
}

ll fibonacci(ll A, ll B, ll  n) {
	if(n == 0) return 0;
	if(n == 1 || n == 2) return 1;

	ll a[2][2] = { {A, B}, {1, 0} };
	ll s[2][2] = { {1, 0}, {0, 1} };
	pow(s, a, n-2);
	return s[0][0] + s[0][1];
}
#endif

#if 0		// 递推法求解 - 时间复杂度为O(n) - 运行结果： Time limit exceeded 
ll fibonacci(ll A, ll B, ll  n) {
	if(n == 0) return 0;
	if(n == 1 || n == 2) return 1;
	ll num[2] = {1, 1};
	ll sum;
	for (int i = 3; i <= n; ++i) {
		sum = (A*num[1] + B*num[0]) % m_remainder;
		num[0] = num[1];
		num[1] = sum;
	}
	return sum;
}
#endif

int main_1126_AC() {		// 通过AC测试的 main() 函数
	ll n;
	ll sum;
	ll A,B;
	cin >> A >> B >> n;

	sum = fibonacci(A, B, n);
	cout<<sum<<endl;
	getchar();
	return 0;
}

int main_1126_Test() {

#if 0
	long long n;
	long long sum;

	n = 5024295251;
	long long i = n;
	while (i <= n)
	{
		sum = fibonacci(i);
		sum %= m_remainder;  
		cout << sum << "%n";
		++i;
	}
#endif

	while (1) {
		ll n;
		ll sum;
		ll A,B;
		cin >> A >> B >> n;

		sum = fibonacci(A, B, n);
		cout << "f(" << n << ") = "<< sum << endl ;			// f(n) = sum
	}
	

	return 0;
}

