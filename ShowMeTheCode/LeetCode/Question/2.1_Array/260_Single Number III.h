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

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. 
Could you implement it using only constant space complexity?

题目网址： 
https://leetcode.com/problems/single-number-iii/

*/

// 方法一
// 异或 位运算技巧
/*
    对于任何数x，都有x^x=0，x^0=x。
    异或运算 满足 交换律。 a^b^c = a^c^b
*/ 

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int c = 0, a = 0, b = 0;

		// 取得 a ^ b 的结果  
		for (int n : nums) {
			c ^= n;
		}

		// 获取第1个非0的位。
		int firstZero = c & (~c + 1);

		// 开始筛选出a 和 b
		for (int m : nums) {
			if ((m & firstZero) != 0) {
				a ^= m;
			}
		}
		b = c ^ a;

		vector<int> ret;
		ret.push_back(a);
		ret.push_back(b);

		return ret;
	}
};

//=========================================================================
//						测试用例
//=========================================================================
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


//=========================================================================
//						总结
//=========================================================================
/*
总结：一个数组中，所有数都出现了偶次，只有2个数出现了 奇数次，那么都可以用这个方法


*/