#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*     1031_骨牌覆盖
在2*N的一个长方形方格中，用一个1*2的骨牌排满方格。
问有多少种不同的排列方法。

例如：2 * 3的方格，共有3种不同的排法。（由于方案的数量巨大，只输出 Mod 10^9 + 7 的结果）

Input
输入N(N <= 1000)
Output
输出数量 Mod 10^9 + 7

题目网址：http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1031

话题：斐波那契数列 组合数学 矩阵乘法 快速幂 

*/

typedef long long ll;

const ll m_remainder = 1000000009;
const ll m_initNum[3] = {1, 1, 2};		// 定义初始项： 第0～2项


// 矩阵乘法 a * b [矩阵乘法-是不满足交换律的，切记]
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
		if(n&1) mul(s, a, s);
		mul(a, a, a);
		n >>= 1;
	}
}

ll fibonacci(ll  n) {

	if( n > -1 && n < 3) return m_initNum[n];

	ll a2 = m_initNum[2];
	ll a1 = m_initNum[1];

	ll a[2][2] = { {1, 1}, {1, 0} };
	ll s[2][2] = { {2, 0}, {0, 1} };
	pow(s, a, n-2);
	return s[0][0] + s[0][1];
}

int main_AC() {		// 用来通过AC测试的 main() 函数
	long long n;
	long long sum;
	cin>>n;

	sum = fibonacci(n);
	sum %= m_remainder;  
	cout<<sum;
	return 0;
}

int main_Test() {		// 用来输出测试的 函数。

	long long n;
	long long sum;

#if 1
	while (1) {
		cin >> n;
		sum = fibonacci(n);
		sum %= m_remainder;  
		cout << "f(" << n << ") = "<< sum << endl ;			// f(n) = sum
	}
#endif
	return 0;

}

