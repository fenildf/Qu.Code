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

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

题目网址： 
https://leetcode.com/problems/candy/

*/

// 方法1， 时间复杂度 O(n),逻辑好复杂  
/*
   遇到 比前面 大的元素，就 +1.
   遇到拐点：凹点 或者 最右边的边界点时，就进行逆向计算，计算比较复杂
   遇到两个相邻的相同的元素时，就相当于 新开了一个数组， 开始计算了。
*/ 
class Solution {
public:
	int candy(vector<int>& ratings) {
		int lastHightIndex = 0;
		int lastCandy = 1;
		int sum = 1;
		for (int i = 1; i < ratings.size(); ++i) {
			if (ratings[i] > ratings[i-1]) {
				lastHightIndex = i;
				sum += (++lastCandy);
			} else if (ratings[i] < ratings[i-1] && (i == ratings.size() - 1 || ratings[i] <= ratings[i+1])) {
				int sumSonMax = i - lastHightIndex;
				if (sumSonMax + 1 > lastCandy) {
					sum += sumSonMax + 1 - lastCandy;
				}
				sum += (sumSonMax + 1) * sumSonMax / 2;     // 求和公式
				lastCandy = 1;

			} else if (ratings[i] == ratings[i-1]) {        // 当相等的时候， 其实就是相当于从 左端点重新开始了。
				lastHightIndex = i;
				lastCandy = 1;
				sum += (lastCandy);
			}
		}

		return sum;
	}
};


// 方法2，从左右扫描2遍，看了 别人的解题策略。
/*
	时间复杂度 O(2n)
*/
class Solution {
public:
	int candy(vector<int>& ratings) {
		const int n = ratings.size();
		vector<int> sum(n,1);

		for (int i = 1; i < n; ++i) {
			if (ratings[i] > ratings[i-1]) {
				sum[i] = sum[i-1] + 1;
			} 
		}

		for (int i = n - 2; i > -1; --i) {
			if (ratings[i] > ratings[i + 1]) {
				sum[i] = (sum[i + 1] + 1) > sum[i] ? sum[i + 1] + 1 : sum[i];       // 比原来的值大，就替换
			} 
		}

		// 统计所有和
		int sumRet = 0;
		for (int i = 0; i < n; ++i) {
			sumRet += sum[i];
		}
		return sumRet;
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