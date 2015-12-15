#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

/*

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Subscribe to see which companies asked this question

题目网址： 
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

*/

// 方法一
// 遍历法
class Solution1 {
public:
	bool search(vector<int>& nums, int target) {
		bool a = false;
		int i = 0;
		for(int n : nums) { 
			if (n == target) {
				a = true;
				return a;
			}
			++i;
		}
		return a;
	}
};



// 方法二
// 我自己想出来的方法
class Solution {
public:
	typedef struct State {
		int start;
		int end;
	}state;

	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) return false;  

		state tempS = {0,nums.size() - 1};
		queue<state>  startQ;
		startQ.push(tempS);

		while (!startQ.empty()) {
			tempS = startQ.front();		// 取出队首元素
			startQ.pop();

			int mid = (tempS.end + tempS.start)/2; 
			state tem;

			  
			if ( tempS.end - tempS.start > 1 && 
				(	nums[tempS.start] == nums[tempS.end] ||  // 如果前后端点都相同的情况下，那时就没有办法进行判断到底是删去左边区间还是右边区间了，只能全部压入 队列中，去遍历循环
					nums[tempS.start] > nums[mid] ||		// 断点在mid前边
					nums[tempS.end] < nums[mid] ||			// 断点在mid后边
					(target < nums[tempS.end] && target > nums[tempS.start])) ) {  // 没有断点，但是点落在2个端点之间了。
				tem.start = tempS.start;
				tem.end = (mid-1 > -1) ? mid-1 : 0;
				startQ.push(tem);

				tem.start = mid;
				tem.end = tempS.end;
				startQ.push(tem);
			} else if (target == nums[tempS.end] || target == nums[tempS.start]) {
				return true;
			}

		}

		return false;
	}
};

// 测试例子：
/*
	int array[] = {1,3,1,1,1};
	vector<int> nums(array, array+5);
	int target = 3;

	Solution* test = new Solution();
	bool res  = test->search(nums, target);

*/




// 方法三
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int first = 0, n = nums.size();
		int last = n - 1;

		while(first <= last) {
			const int mid = (last + first)/2;

			if (nums[mid] == target) return true;

			if (nums[first] < nums[mid]) {					//left half is sorted
				if ( nums[first] <= target && target < nums[mid])
				{
					last = mid;
				} else {
					first = mid + 1;
				}
			}else if (nums[first] > nums[mid]) {			//right half is sorted
				if (nums[mid] < target && target <= nums[last])
				{
					first = mid + 1;
				} else {
					last = mid;
				}
			} else {	// 无法确定要缩减哪一半。
				first++;		//skip duplicate one
			}
		}
		return false;
	}
};



int main_AC() {		// 用来通过AC测试的 main() 函数

	// time_t 获得时间只能精确到秒,clock_t 获得时间能够精确到毫秒

	system("pause");		// 请按任意键继续。。。

	int array[] = {1,3,1,1,1};
	vector<int> nums(array, array+5);
	int target = 3;
	// 跑一个例子

	Solution* test = new Solution();
	bool res  = test->search(nums, target);

	system("pause");		

	return 0;
}
