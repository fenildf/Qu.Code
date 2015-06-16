


// __________________________35- Search Insert Position __________________________
/*
题目来源:

https://leetcode.com/problems/search-insert-position/
http://www.lintcode.com/zh-cn/problem/search-insert-position/

*/  


/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

// __________________________ Tags __________________________
/*
	 Array,Binary Search
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n)
/*

*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target || nums[i] > target) return i;
        }
        return nums.size();    // end insert
    }
};


// 代码2
// 用了 二分查找方法的 【有问题，暂时不行】
class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        // int n = A.size() / 2; 
        int length = A.size()/2; 
        for (int i = length; i < A.size() || length == 1; length /= 2) {
            if (A[i] == target ) return i;
            if (A[i] < target) i += length;
            if (A[i] > target) i -= length;
        }
        return length;
        return A.size();    // end insert
    }
};