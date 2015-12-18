#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include<time.h>
using namespace std;

/*

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

题目网址： 
https://leetcode.com/problems/single-number-ii/

*/

// 方法一
// 异或 位运算技巧 之 模拟三位数运算
// 居然知道用 三位数 运算 方法的情况下，都写了1个小时的代码，好在一次性AC过了。
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int one = 0, two = 0, three = 0;

		for (int n : nums) {
			two |= (one & n);	// 更新 two 里要增加的 1位
			one ^= n;			// 更新 one 位。

			three = two & one;
			one &= (~three);	// 满3位了清0
			two &= (~three);	// 满3位了清0
		}

		return one;
	}
};


// 方法二
// 自己思考了 for 循环的 第1轮，第2轮，第3轮，居然都是对的，这个式子太神奇。
class Solution3 {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0, three = 0;

		for (int n : nums) {
			ones = (ones ^ n) & ~twos;
			twos = (twos ^ n) & ~ones;
		}

		return ones;
	}
};

/*
	从布尔代数上面考虑， 就只有三种状态进行循环：
	然后我们需要2位来表示三种状态，ones 代表第1位，twos 代表第2位。
	00，01，10， [11 就变为 00]
	每次 n 为 1 的时候，ones 的状态就发生变化，进行如下循环： 0->1->0->0

	(ones ^ n) 的含义就是：
	n 每次为1的时候，ones就进行变化 按照 0-1-0-1-0这样变化。

	----------------------------------------------------------------

	& ~twos 的含义就是：
	if (twos == 1) then ones = 0
	所以当 twos = 1的时候，ones再由1变化过来就变成0了。
	也就是由 0-1-0-1-0 变化为： 0->1->0->0

	----------------------------------------------------------------
	----------------------------------------------------------------
	每次 n 为 1 的时候，twos 的状态就发生变化，进行如下循环： 0->0->1->0

	(two ^ n) 的含义就是：
	n 每次为1的时候，two就进行变化 按照 0-1-0-1-0这样变化。

	& ~ones 的含义就是：
	if (ones == 1) then twos = 0

	这样twos的变化就由 0-1-0-1-0 变化为： 0->0->1->0
	
	----------------------------------------------------------------
	twos = (twos ^ n) & ~ones;	
	if (two == 0 && n == 1 && ones* == 0) then two = 1
	这里 ones* 是更新后[与n计算过]的one.
	所以 one 的计算要放在 two 前面了。
*/


/*	网上的解释，非常的清楚。
https://leetcode.com/discuss/6632/challenge-me-thx

The code seems tricky and hard to understand at first glance. However,
if you consider the problem in Boolean algebra form, everything becomes clear.

What we need to do is to store the number of '1's of every bit. Since each of the 32 bits follow the same rules, we just need to consider 1 bit. 
We know a number appears 3 times at most, so we need 2 bits to store that. Now we have 4 state, 00, 01, 10 and 11, but we only need 3 of them.

In this solution, 00, 01 and 10 are chosen. Let 'ones' represents the first bit, 'twos' represents the second bit. 
Then we need to set rules for 'ones' and 'twos' so that they act as we hopes. The complete loop is 00->10->01->00(0->1->2->3/0).

For 'ones', we can get 'ones = ones ^ A[i]; if (twos == 1) then ones = 0', that can be tansformed to 'ones = (ones ^ A[i]) & ~twos'.

Similarly, for 'twos', we can get 'twos = twos ^ A[i]; if (ones* == 1) then twos = 0' and 'twos = (twos ^ A[i]) & ~ones'.
Notice that 'ones*' is the value of 'ones' after calculation, that is why twos is calculated later.

*/



//=========================================================================
//						延伸题目 - 01
//=========================================================================
/*
	给你一个整数数组，里面所有的数字都出现5次，除了1个数字只出现了1次。找出这个只出现了1次的数。
*/

/*	分析：
	布尔代数状态分析：
	我们需要3位来表示5次，ones 代表第1位，twos 代表第2位，threes 代表第3位。
	000 001 010 011 100 [101 就变为 000]

	n为0的时候，ones 的状态不发生变化。
每次 n为1 的时候：
	ones	的状态就发生变化，进行如下循环： 0->1->0->1->0->0
	twos	的状态就发生变化，进行如下循环： 0->0->1->1->0->0
	threes	的状态就发生变化，进行如下循环： 0->0->0->0->1->0

	仔细观察这3行，我们可以发现好几个规律：
	看上面第2行， 当 ones 的值为1的时候， twos 的值不进行翻转，保存上一个值。。
	
	// if (three == 1) then ones = 0
	ones = (ones ^ n) & (~three);

	// if (ones == 1) then twos 的值不进行翻转。
	(twos ^ (n  & (~ones)))

	three = (three ^ n) & (~ones) & (~twos);


*/


class Solution5 {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0, three = 0;

		for (int n : nums) {

			cout << n << " ";
			ones =  (ones ^ n) & (~three);
			twos =  (twos ^ (n  & (~ones)))  & (~three);
			three = (three ^ n) & (~ones) & (~twos);
		}
		cout << endl;

		return ones;
	}
};
 

// 单元测试用例
class unitTest {
public:
	void creatTestData(vector<int>& nums) {

#if 1
		// 产生 目标数据
		int goal = rand();
		nums.push_back(goal);
		wcout << "只出现了1+5i次的数字为： " << goal << endl;

		// 产生 测试数据
		for (int j = 0; j < 15; ++j) {
			int randNum = rand();
			for (int i = 0; i < 5; ++i) {
				nums.push_back(randNum);

				int ers = 23;
			}
		}
#else
		int array[] = { 

			2,2,2,2,2,
			3,3,3,3,3,
			56,56,56,56,56,

			11,
			//2,3, 56,
			//2,3, 56,
			//2,3, 56,
			//2,3, 56,
			//2,3, 56,

			//3,21,8,71,
			//3,21,8,71,
			//3,21,8,71,
			//3,21,8,71,
			//3,21,8,71,
		};
		vector<int> numLs(array, array+(sizeof (array) / sizeof (array[0])) );		

		nums = numLs;
#endif


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
		Solution5* test = new Solution5();
		int res  = test->singleNumber(nums);
		cout << "找到的数字为: " << res << endl;
		cout << endl;

		system("pause");
	}
}


//=========================================================================
//						延伸题目 - 02
//=========================================================================
/*
	给你一个整数数组，里面所有的数字都出现7次，除了1个数字只出现了1次。找出这个只出现了1次的数。
*/

/*	分析：
	布尔代数状态分析：
	000 001 010 011 100 101 110 [111 就变为 000]

	每次 n为1 的时候：
	ones	的状态就发生变化，进行如下循环： 0->1->0->1->0->1->0->0
	twos	的状态就发生变化，进行如下循环： 0->0->1->1->0->0->1->0
	threes	的状态就发生变化，进行如下循环： 0->0->0->0->1->1->1->0
*/

// 好吧，我们不是来 学习 数字电子技术基础 的 ... ...
// 越来越像用 门电路来解题了。


/*
	总结：一个数组中，所有数都出现了相同的奇数次，只有1个数出现了 1次，那么都可以用这个方法来做。


*/


// 把一个平面变成了一个3D环，好像很NB的样子。
// https://en.wikipedia.org/wiki/Karnaugh_map
