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

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question

题目网址： https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

*/

// 方法一
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;

		int duplicates = 0;

		int index = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[index] != nums[i] ) {
				nums[++index] = nums[i];
				duplicates = 0;
			} else {
				duplicates++;
				if(duplicates == 1) {
					nums[++index] = nums[i];
				}
			}
		}

		return ++index;
	}
};



// 方法二
/*
	这个版本的扩展性非常好，limit = 2 改为 limit = 3，就变成了允许重复最多 3 次。
*/
int removeDuplicates(vector<int>& nums) {
	int i = 0;
	int limit = 2;
	for (int n : nums)
		if (i < limit || n > nums[i-limit])
			nums[i++] = n;
	return i;
}

