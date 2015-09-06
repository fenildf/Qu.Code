#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>		// 打印时间用的
using namespace std;

/*	Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

题目网址： 
https://leetcode.com/problems/factorial-trailing-zeroes/
http://www.lintcode.com/zh-cn/problem/trailing-zeros/

阶乘尾部的零
*/
typedef unsigned int uint32_t;
typedef long long ll;


class Solution {
public:

	// 统计5的个数的版本：运行时间 591ms
	ll trailingZeroesF(ll n) {
		long long sumFive = 0;
				
		for (long long i = 1; n > 0; ++i) {
			sumFive += n/5;			// 第1次筛选，把 5，10，15，20，30，...筛选出来。第2次把 25，50，75，100 刷选出来。
			n /= 5;
		}
		return sumFive;		//
	}

	// 每次增加5的版本，运行时间 8427ms
	ll trailingZeroes(ll n) {
		long long sumFive = 0;
		for (long long i = 5; i < n + 1; i+=5) {
			long long j = i;
			while (0 == j%5) {  // 5-质数分解。
				++sumFive;
				j /= 5;
			}
		}
		return sumFive;
	}
};


int main_AC() {		// 用来通过AC测试的 main() 函数

	// time_t 获得时间只能精确到秒,clock_t 获得时间能够精确到毫秒

	system("pause");		// 请按任意键继续。。。
	clock_t start = clock();

	// 跑一个例子
	ll num = 1001171717;
	Solution* test = new Solution();
	ll ret = test->trailingZeroesF(num);

	// 输出运行时间
	clock_t ends = clock();
	cout << ends - start << endl;		
	system("pause");		

	return 0;
}