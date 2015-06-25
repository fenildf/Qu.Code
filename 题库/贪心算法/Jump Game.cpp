


// __________________________ Jump Game  __________________________
/*
题目来源:
https://leetcode.com/problems/jump-game/
http://www.lintcode.com/zh-cn/problem/jump-game/

跳跃游戏
*/  


/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/

// __________________________ Tags __________________________
/*
	 Greedy-贪心法;
     每个阶段的最优状态都是由上一个阶段的最优状态得到的->贪心；
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用2个for循环  
// 时间复杂度O(n*m),空间复杂度O(m)。
// 使用1维数组-记录以前的状态。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> pass(nums.size(),0);    // 0表示不能到达终点，1表示能够到达终点
        
        for (int i = nums.size()-1; i >= 0; --i) {
            for (int j = 0; j <= nums[i]; ++j) {
                // 1-到达数组边界；2-遇到为true的节点
                if (i + j >= nums.size()-1 || pass[i+j] == true) {   
                    pass[i] = true;
                    break;
                }
            }
        }
        
        return pass[0];
    }
};

/*
在 lintcode 网站，上面的代码就 可以跑通过。

在 leetcode 网站 跑代码时， 如下数据时，直接超时。
Last executed input:
[25000,24999,24998,24997,24996,24995,24994,24993,24992,24991,24990,24989,24988,24987,24986,24985,24984,24983,24982,2
... ... 3,2,1,0,0,]
*/


//  代码2 - 使用 贪心 算法
/*
    第2层 for 循环其实是没必要全部 遍历一遍的。 
    改进：
    检测 能否到达 上一阶段（i+1）的离你最近的一个可通行节点.
*/  
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int borad = nums.size()-1;           // 初始时最优状态就是最后一个元素。
        
        for (int i = nums.size()-1; i >= 0; --i) {            
            if (i + nums[i] >= borad) {     // 1-到达上一个阶段的最优状态
                borad = i;                  // 2-如果能到达，i就变成现在这个阶段的最优状态。
            }
        }
        
        return (borad == 0) ? true : false;
    }
};
