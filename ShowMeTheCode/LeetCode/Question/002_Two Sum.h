#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*	Two Sum

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

题目网址： https://leetcode.com/problems/two-sum/

*/
typedef unsigned int uint32_t;
uint32_t bitmapOne[32];     //      1,     10,      100,     1000,  ...
uint32_t bitmapZero[32];    // 111110，111101， 1111011， 1110111， ...
bool m_isInit = false;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> pool = nums;

		sort(pool.begin(), pool.end());

		int i;
		for (i = 0; i < nums.size(); ++i) {
			int midTar;
			midTar = target - pool[i];
			if (binary_search(pool.begin(), pool.end(), midTar)) {
				break;
			}
		}

		// 找到要查找的数了。
		int a = pool[i];
		int b = target - pool[i];

		// 接下来确定 A 和 B 在 nums中的位置。
		vector<int> res;
		for(int j = 0; j < nums.size(); ++j) {
			if(nums[j] == a || nums[j] == b) {
				if (res.size() == 0) {
					res.push_back(j+1);
				} else if (nums[j] + nums[res[0]-1] == target) {    // 找对值了
					res.push_back(j+1);
					break;
				}
			}
		}

		return res;
	}
};


int main_AC() {		// 用来通过AC测试的 main() 函数
	int array[4] = {0,4,3,0};
	vector<int> nums(array, array+4);

	Solution* test = new Solution();
	vector<int> res = test->twoSum(nums, 0);
	
	return 0;
}