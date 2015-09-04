/*     1087_1 10 100 1000

1,10,100,1000...组成序列1101001000...，求这个序列的第N位是0还是1。
Input
第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10000)
第2 - T + 1行：每行1个数N。（1 <= N <= 10^9)
Output
共T行，如果该位是0，输出0，如果该位是1，输出1。

题目网址：
http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1087



*/

#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*
0 1  3   6    10   15
1 2  4   7    11   16

f(0) = 1
f(1) = 2
f(2) = 4
f(n) = f(n-1) + n = n(n+1)/2 +1

*/

// 需要快速开方的知识。

ll pow(ll a, ll n, ll c){
	ll s = 1;
	while(n > 0){
		if(n&1) {
			s = s*a%c;
		};
		a = a*a%c;
		n >>= 1;
	}
	return s;
}



int main_AC() {		// 用来通过AC测试的 main() 函数
	ll sum,a,b,c;
	sum = 1;

	cin >> a >> b >> c;
	sum = pow(a, b, c);

	cout<<sum;
	return 0;
}

int main_Test() {
	ll sum,a,b,c;
	sum = 1;

	while (1) {
		cin >> a >> b >> c;
		sum = pow(a, b, c); 
		cout << a << " ^ " << b << " % " << c<< " = "<< sum << endl ;			// A^B % C = sum
	}

	return 0;
}