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

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

题目网址： 
https://leetcode.com/problems/climbing-stairs/

*/

// 方法一
// 
/*
    
*/ 
class Solution {
public:
	vector<int> plusOne(vector<int>& digits, int num) {
		add(digits, num);
		return digits;
	}

	vector<int> plusOne(vector<int>& digits) {
		add(digits, 1);
		return digits;
	}
private:
	void add(vector<int>& digits, int num) {
		int sum = 0;
		if ( 0 < num) {
			for (int i = digits.size() -1; i > -1; --i) {
				sum += digits[i] + num%10;
				digits[i] = sum%10;
				sum /= 10;
				num /= 10;
				if (sum == 0 && num == 0) break;
			}

			while (sum > 0)
			{
				digits.insert(digits.begin(),sum%10);
				sum /= 10;
			}
		}
	}
};

//=========================================================================
//						单元测试
//=========================================================================
#if 1
class unitTest {
public:
	int creatTestData(vector<int>& nums) {

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
			int addNum = testData->creatTestData(nums);

			// 跑代码例子
			Solution* test = new Solution();
			vector<int> res  = test->plusOne(nums, addNum);
	
			cout << " + " << addNum << " = ";
			for (int n : res) {
				cout << n;
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