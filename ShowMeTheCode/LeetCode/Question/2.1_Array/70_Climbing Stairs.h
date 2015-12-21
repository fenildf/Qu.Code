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
using namespace std;

/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

题目网址： 
https://leetcode.com/problems/climbing-stairs/

*/

// 方法一
// 
/*
    
*/ 

class Solution {
public:
	int climbStairs(int n) {
		int a[3] = {1,1,2,};

		for (int i = 0; i < n; ++i)
		{
			a[2] = a[0] + a[1];
			a[0] = a[1];
			a[1] = a[2];
		}

		return a[0];
	}
};

//=========================================================================
//						测试用例
//=========================================================================
#if 0
class unitTest {
public:
	void creatTestData(vector<int>& nums) {

		// 产生 目标数据
		int goalOne = rand();
		nums.push_back(goalOne);
		int goalTwo = rand();
		nums.push_back(goalTwo);

		wcout << "只出现了1次的2个数字为： " << goalOne << " " << goalTwo << endl;

		// 产生 测试数据
		for (int j = 0; j < 10; ++j) {
			int randNum = rand();
			for (int i = 0; i < 2; ++i) {
				nums.push_back(randNum);
			}
		}

	}
};


void main_AC() {	

	system("pause");		// 请按任意键继续。。。
	srand ((unsigned)time(nullptr));	// 这个只能初始化1次	
	vector<int> nums;

	while (1)
	{
		// 产生测试数据
		nums.clear();
		unitTest* testData = new unitTest();
		testData->creatTestData(nums);

		// 跑代码例子
		Solution* test = new Solution();
		vector<int> res  = test->singleNumber(nums);
		cout << "找到的数字为: " << res[0] << "  " << res[1] << endl;
		cout << endl;

		system("pause");
	}
}
#endif

//=========================================================================
//						总结
//=========================================================================
/*



*/