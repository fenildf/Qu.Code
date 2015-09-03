/*     1046_A^B Mod C

给出3个正整数A B C，求A^B Mod C。
例如，3 5 8，3^5 Mod 8 = 3。
Input
3个正整数A B C，中间用空格分隔。(1 <= A,B,C <= 10^9)

题目网址：http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1046

话题：快速幂 

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