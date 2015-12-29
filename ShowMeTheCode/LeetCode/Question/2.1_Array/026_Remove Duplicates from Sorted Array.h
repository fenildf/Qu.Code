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

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question

题目网址： https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/

// 方法一
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;

		int index = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[index] != nums[i]) {
				nums[++index] = nums[i];
			}
		}

		return ++index;
	}
};



// 方法二， 就是使用了个模板
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		return removeDuplicate(nums);
	}

	template<typename Init>
	int removeDuplicate(vector<Init>& nums) {
		if (nums.size() == 0) return 0;

		int index = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[index] != nums[i]) {
				nums[++index] = nums[i];
			}
		}

		return ++index;
	}
};

// 方法三
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		return distance(nums.begin(), unique(nums.begin(),nums.end()));
	}
};

// 方法四
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0;
		for (int n : nums) {
			if (i < 1 || n > nums[i-1]) nums[i++] = n;
		}
			
		return i;
	}
};