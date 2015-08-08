


// __________________________ First Missing Positive __________________________
/*
题目来源:

https://leetcode.com/problems/first-missing-positive/
http://www.lintcode.com/zh-cn/problem/first-missing-positive/

丢失的第一个正整数
*/  


/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

// __________________________ Tags __________________________
/*
	Array, 
*/

// __________________________ 实现细节 __________________________ 

// 代码1 -使用STL
// 时间复杂度
// 
class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
     
    bool static RemoveItem(int item)
    {
        if (item < 1) {
            return true;
        } else {
            return false;
        }
    }
    
    int firstMissingPositive(vector<int> nums) {
        // write your code here
        if(nums.size() == 0) return 1;
        
        // 先把负数干掉
        nums.erase(std::remove_if(nums.begin(),nums.end(),RemoveItem), nums.end());
        // 再排序
        sort(nums.begin(), nums.end());
        // 再去掉重复元素
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        // 再用二分查找【以后使用】
        for (int i = 1; i < nums.size()+1; ++i) {
            if (nums[i-1] != i) {
               return i; 
            }
        }
        
        return nums.size() + 1;
    }
};

