#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<numeric>		// 使用 accumulate
#include<functional>	// 使用 bit_xor
using namespace std;

/*

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

题目网址： 
https://leetcode.com/problems/single-number/

*/

// 方法一
// 异或 位运算技巧
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int n : nums) {
			res ^= n;
		}
		return res;
	}
};




// 方法二
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		
		return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
	}
};