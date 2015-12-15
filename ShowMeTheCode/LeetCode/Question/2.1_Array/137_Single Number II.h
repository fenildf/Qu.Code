#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

/*

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

题目网址： 
https://leetcode.com/problems/single-number-ii/

*/

// 方法一
// 异或 位运算技巧 之 模拟三位数运算
// 居然知道用 三位数 运算 方法的情况下，都写了1个小时的代码，好在一次性AC过了。
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int one = 0, two = 0, three = 0;

		for (int n : nums) {
			two |= (one & n);	// 更新 two 里要增加的 1位
			one ^= n;			// 更新 one 位。

			three = two & one;
			one &= (~three);	// 满3位了清0
			two &= (~three);	// 满3位了清0
		}

		return one;
	}
};




