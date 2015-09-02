// __________________________ Majority Element   __________________________
/*
题目来源:

https://leetcode.com/problems/majority-element/

http://www.lintcode.com/zh-cn/problem/majority-number/

主元素
*/  


/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

// __________________________ Tags __________________________
/*
	 Enumeration
*/

// __________________________ 实现细节 __________________________ 
// 代码1 -遍历

// 代码2 - 排序后找中间数
// 时间复杂度O(1),空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// 代码3 - 不用排序也能找到


// __________________________ Majority Element II __________________________
/*
题目来源:
https://leetcode.com/problems/majority-element-ii/

http://www.lintcode.com/en/problem/majority-number-ii/

主元素2
*/  


/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Note
There is only one majority number in the array.

Challenge
O(n) time and O(1) extra space.
*/

// __________________________ Tags __________________________
/*
     Enumeration
*/

// __________________________ 实现细节 __________________________ 
// 代码1
// 时间复杂度O(1),空间复杂度O(1)