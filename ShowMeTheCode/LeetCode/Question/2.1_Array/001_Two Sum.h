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
#include<time.h>
#include <unordered_map>

using namespace std;

/*

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

题目网址： 
https://leetcode.com/problems/two-sum/

*/

// 方法一  暴力搜索法  时间复杂度：O(n^2)
// 
/*
    
*/ 
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		for( int i = 0; i < nums.size() - 1; ++i ) {
			int sunTarget = target - nums[i];
			for ( int j = i + 1; j < nums.size(); ++j ) {
				if (nums[j] == sunTarget) {
					res.push_back(i + 1);
					res.push_back(j + 1);
					return res;
				}
			}
		}

		return res;
	}
};

// 方法二 hash 方法  时间复杂度：O(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		unordered_map<int, int> mapping;
		for( int i = 0; i < nums.size(); ++i ) {
			mapping[nums[i]] = i;
		}

		for( int i = 0; i < nums.size() - 1; ++i ) {
			int sonTarget = target - nums[i];
			if ( mapping.find(sonTarget) != mapping.end() && mapping[sonTarget] > i ) {
				res.push_back(i + 1);
				res.push_back(mapping[sonTarget] + 1);
				break;
			}
		}

		return res;
	}
};

// 方法3 - 很久以前写的：2015-09-06 号写的，
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

/* 如果不添加  && mapping[sonTarget] > i
Input:
[3,2,4]
6
Output:
[1,1]
Expected:
[2,3]
*/

//=========================================================================
//						单元测试 
//=========================================================================
#if 1
class unitTest {
public:
	int creatTestData(vector<int>& nums) {

		// 生成要寻找的数组
		int arraySit[] = {3,2,4}; 
		nums = vector<int> (arraySit, arraySit+3);

		// 要找寻的相加后的目标数字
		return 6;
#if 0
		// 产生 目标数据
		int goalOne = rand();
		wcout << "要被加的数字为： " << goalOne;

		while (goalOne > 0)
		{
			nums.insert(nums.begin(),goalOne%10);
			goalOne /= 10;
		}

		// 要相加的数字
		int goalTwo = rand();
		return goalTwo;
#endif
	}
};


void main_AC() {	

	system("pause");		// 请按任意键继续。。。
	srand ((unsigned)time(nullptr));	// 这个只能初始化1次	
	vector<int> nums;

	while (1)
	{
		for (int k = 0; k < 10; k++) {
		
			// 产生测试数据
			nums.clear();
			unitTest* testData = new unitTest();
			int sumNum = testData->creatTestData(nums);

			// 跑代码例子
			Solution* test = new Solution();
			vector<int> res  = test->twoSum(nums, sumNum);
	
			cout << " + " << sumNum << " = ";
			for (int n : res) {
				cout << n << " ";
			}
			cout << endl;
		}
		system("pause");
	}
} 
#endif

//=========================================================================
//						总结
//=========================================================================
/*



*/