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

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question

题目网址： 
https://leetcode.com/problems/search-in-rotated-sorted-array/

*/

// 方法一
// 遍历法
class Solution1 {
public:
	int search(vector<int>& nums, int target) {
		int a = -1;
		int i = 0;
		for(int n : nums) { 
			if (n == target) {
				a = i;
			}
			++i;
		}
		return a;
	}
};



// 方法二
// 这个是自己想出来的 ，队列方法。
// 这个方法适合每次循环，可能没法缩减一半的查找空间的方法。
// 所以这种方法 在 081_Search in Rotated Sorted Array II 中将大放光彩。
class Solution2 {
public:
	typedef struct State {
		int start;
		int end;
	}state;

	int search(vector<int>& nums, int target) {
		int res = -1;
		if (nums.size() == 0) return res;  

		state tempS = {0,nums.size() - 1};
		queue<state>  startQ;
		startQ.push(tempS);

		while (!startQ.empty()) {
			tempS = startQ.front();		// 取出队首元素
			startQ.pop();

			int mid = (tempS.end + tempS.start)/2; 
			state tem;

			// 断点在mid前边 || 断点在mid后边 || 没有断点，但是点落在2个端点之间了。
			if ( tempS.end - tempS.start > 1 && (nums[tempS.start] > nums[mid] || nums[tempS.end] < nums[mid] || (target < nums[tempS.end] && target > nums[tempS.start])) ) {
				tem.start = tempS.start;
				tem.end = (mid-1 > -1) ? mid-1 : 0;
				startQ.push(tem);

				tem.start = mid;
				tem.end = tempS.end;
				startQ.push(tem);
			} else if (target == nums[tempS.end] || target == nums[tempS.start]) {
				return (target == nums[tempS.end]) ? tempS.end : tempS.start;
			}

		}

		return res;
	}
};

// 方法三
// 这个解答是看了《leetcode-cpp-题解.pdf》后 ，自己理解了，默写出来的。
// 这个方法适合：每次循环都一定能 删去一半的查找区间的方法。
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int first = 0, n = nums.size();
		int last = n - 1;

		while(first < last) {
			const int mid = (last + first)/2;

			if (nums[mid] == target) return mid;
			if (nums[first] <= nums[mid]) {
				if ( nums[first] <= target && target < nums[mid])
				{
					last = mid;
				} else {
					first = mid + 1;
				}
			}else{
				if (nums[mid] < target && target <= nums[last])
				{
					first = mid + 1;
				} else {
					last = mid;
				}
			}
		}

		return target == nums[first] ? first : -1;
	}
};

int main_AC() {		// 用来通过AC测试的 main() 函数

	// time_t 获得时间只能精确到秒,clock_t 获得时间能够精确到毫秒

	system("pause");		// 请按任意键继续。。。

	int array[] = {1};
	vector<int> nums(array, array+1);

	int target = 1;
	// 跑一个例子

	Solution* test = new Solution();
	int res  = test->search(nums, target);
	
	system("pause");		

	return 0;
}

