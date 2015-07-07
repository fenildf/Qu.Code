


// __________________________ Single Number II  __________________________
/*
题目来源:

https://leetcode.com/problems/single-number-ii/
http://www.lintcode.com/zh-cn/problem/single-number-ii/

*/  


/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

// __________________________ Tags __________________________
/*
	 Bit Manipulation ，Hash Table
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用 位运算 模拟 三进制运算
// 时间复杂度O(n),空间复杂度O(1)
/*
    对于除出现一次之外的所有的整数，其二进制表示中每一位1出现的次数是3的整数倍，将所有这些1清零，剩下的就是最终的数。
    用ones记录到当前计算的变量为止，二进制1出现“1次”（mod 3 之后的 1）的数位。
    用twos记录到当前计算的变量为止，二进制1出现“2次”（mod 3 之后的 2）的数位。
    当ones和twos中的某一位同时为1时表示二进制1出现3次，此时需要清零。
    即用二进制模拟三进制计算。最终ones记录的是最终结果。
*/ 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, xthree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            twos |= (ones & nums[i]);    // 记录当前位遇到2次1没有
            ones ^= nums[i];             // 记录当前位遇到1次1没有
            xthree = (ones & twos);      // 记录当前位遇到3次1没有,并且不用保留上次循环的状态 
            ones &= ~xthree;             // 当有的位 遇到3次1时，清0
            twos &= ~xthree;             // 当有的位 遇到3次1时，清0
        }
        
        return ones;
    }
};