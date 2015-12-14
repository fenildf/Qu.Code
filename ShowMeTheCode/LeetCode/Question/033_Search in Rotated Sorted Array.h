#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question

题目网址： https://leetcode.com/problems/search-in-rotated-sorted-array/

*/

// 方法一
// 遍历法
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int a = -1;
		int i = 0;
		for(int n : nums) { 
			if (n == target) {
				a = i;
			}
			++i;
		}
		return a;
	}
};



// 方法二
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int res = -1;
		if (nums.size() == 0) return res;  

		int begin = 0;
		int end = nums.size() - 1;
		int mid = nums.size()/2;


		for (begin != end) {
			// 断点在mid前边
			if (nums[begin] > nums[mid]) {

			}

			// 断点在mid后边
			if (nums[end] < nums[mid]) {

			}
		}

		return res;
	}
};
