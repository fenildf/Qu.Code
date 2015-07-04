


// __________________________ Single Number  __________________________
/*
题目来源:

http://www.lintcode.com/zh-cn/problem/single-number/
https://leetcode.com/problems/single-number/

*/  


/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

// __________________________ Tags __________________________
/*
	 Bit Manipulation ，Hash Table
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用 异或的 特殊属性。
// 时间复杂度O(n),空间复杂度O(1)
/*
    对于任何数x，都有x^x=0，x^0=x。
    异或运算 满足 交换律。 a^b^c = a^c^b
*/ 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xorSum = xorSum ^ nums[i];
        }
        
        return xorSum;
    }
};


/*
    google面试题的变形：一个数组存放若干整数，一个数出现奇数次，其余数均出现偶数次，
    找出这个出现奇数次的数？

    同样用 上面的代码  int singleNumber(vector<int>& nums)  来计算。
*/


/*
    1-1000放在含有1001个元素的数组中，只有唯一的一个元素值重复，其它均只出现一次。
    每个数组元素只能访问一次，设计一个算法，将它找出来；
    不用辅助存储空间，能否设计一个算法实现？

    long sum = (1+1000)×1000/2 = 500500;
    int num = sum - A[i](0~1000)    //  得到了要找的元素的 负值。
    return (-1)*num;
*/    