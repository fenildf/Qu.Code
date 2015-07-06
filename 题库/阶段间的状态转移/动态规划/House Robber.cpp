


// __________________________198 - House Robber  __________________________
/*
题目来源:
https://leetcode.com/problems/house-robber/
http://www.lintcode.com/en/problem/house-robber/

*/  


/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is 
that adjacent houses have security system connected and it will automatically contact 
the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example
Given [3, 8, 4], return 8.

return 3

Challenge
O(n) time and O(1) memory.
*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - for 循环
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0]; 
        
        long right_zero   = nums[0];    // 右侧不打劫   [1 0]
        long rigth_one    = nums[1];    // 右侧打劫     [0 1]   
        
        if (nums.size()%2 == 1) nums.push_back(0);    // 奇数 补成 偶数
        
        for (int i = 2; i < nums.size(); i += 2) {
            long temp;
            // 计算 rigth_one
            temp = ((rigth_one > right_zero) ?  \
            rigth_one : right_zero) + nums[i+1];
            
            // 计算 right_zero
            right_zero = (right_zero + nums[i]) > rigth_one ? right_zero + nums[i] :  rigth_one;

            
            rigth_one = temp;
        }
        
        return (rigth_one > right_zero) ? rigth_one : right_zero;
    }
    
};










