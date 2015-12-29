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

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

题目网址： 
https://leetcode.com/problems/remove-element/

*/

// 方法一  暴力搜索法  时间复杂度：O(n)
// 
/*
    
*/ 
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int index = 0;
		for (int m : nums) {
			if (m != val) {
				nums[index++] = m;
			}
		}
		return index;
	}
};

// 方法二 使用STL - distance + remove
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
	}
};

/* 
*/

//=========================================================================
//						单元测试 
//=========================================================================
#if 0
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