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

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

题目网址： 
https://leetcode.com/problems/gray-code/

*/

// 方法1  
/*
    第1个 gray 码 必须是 0， 所以 即使 n = 0 的时候， res = {0};
*/ 
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);

		for(int i = 0; i < n; i++) {
			int high_bit = 1 << i;
			for (int j = res.size() - 1; j >= 0; --j) {
				res.push_back(res[j]|high_bit);
			}
		}

		return res;
	}
};

// 方法2 - 使用数学公式推导
/*
    待看。
*/ 


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