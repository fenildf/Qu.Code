


// __________________________ Minimum Subarray  __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/minimum-subarray/

最小子数组
*/  


/*
Given an array of integers, find the subarray with smallest sum.

Return the sum of the subarray.


Example
For [1, -1, -2, 1], return -3

Note
The subarray should contain at least one integer.
*/

// __________________________ Tags __________________________
/*
	 
*/

// __________________________ 所用到的数据结构 __________________________


// __________________________ 实现细节 __________________________ 
// 代码1 - 暴力版，如果数组很大，肯定会超时
// 时间复杂度O(n^2)
class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int minSum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                minSum = min(minSum, sum);
            }
        }
        
        return minSum;
    }
};


// __________________________ Maximum Subarray  __________________________
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int sum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int sumTemp = 0;
            
            for (int j = i; j < nums.size(); ++j) {
                sumTemp += nums[j];
                sum = max(sum, sumTemp);
            }
        }
        
        return sum;
    }
};