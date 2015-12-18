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
/*
    对于任何数x，都有x^x=0，x^0=x。
    异或运算 满足 交换律。 a^b^c = a^c^b
*/ 
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


/*
	总结：一个数组中，所有数都出现了偶次，只有1个数出现了 奇数次，那么都可以用这个方法：
	把所有数 异或起来，剩下的结果就是那个只出现了奇数次的数。 

*/