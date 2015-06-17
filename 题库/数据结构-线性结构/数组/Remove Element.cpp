


// __________________________27- Remove Element  __________________________
/*
题目来源:

https://leetcode.com/problems/remove-element/
http://www.lintcode.com/zh-cn/problem/remove-element/#

*/  


/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*/

// __________________________ Tags __________________________
/*
	 Array,Two Pointers
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n),空间复杂度O(1)
/*
  可能会影响速度的地方：
   如果从头到尾都没有 要去除的元素，就会白白全部赋值一遍。但是好像加了 if 判断也没快。
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int back = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[back++] = nums[i];
        }
        return back;
    }
};



// 加了 if 判断的。速度都是一样的。
class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int back = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != elem) {
                if (back == i) {
                   ++back;
                   continue;
                }
                A[back++] = A[i];
            } 
        }
        return back;
    }
};


// 代码2
// 使用 stl 中的 remove()
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};