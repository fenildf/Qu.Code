


// __________________________ Single Number III  __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/single-number-iii/

*/  


/*
Given 2*n + 2 numbers, every numbers occurs twice except two, find them.

Have you met this question in a real interview? Yes
Example
Given [1,2,2,3,4,4,5,3] return 1 and 5

Challenge
O(n) time, O(1) extra space.
*/

// __________________________ Tags __________________________
/*
	 Bit Manipulation 
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用 异或的 特殊属性。
// 时间复杂度O(2n),空间复杂度O(1)
/*
    对于任何数x，都有x^x=0，x^0=x。
    异或运算 满足 交换律。 a^b^c = a^c^b
*/ 
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &nums) {
        // write your code here
        int xorSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xorSum = xorSum ^ nums[i];
        }

        // 输出 xorSum 的低位中的第一个 1 的位置
        int firstOneBit = xorSum & ~(xorSum - 1);   // 在这位上，a和b 不一样，一个为1，一个为0，就这样把a和b过滤出来。

        int a = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] & firstOneBit) {
                a ^= nums[j];       // 把B过滤了，因为B在这位为0
            }
        }
        
        int b = xorSum ^ a;
        
        vector<int> singleOne;
        singleOne.push_back(a);
        singleOne.push_back(b);
        
        return singleOne;
    }
};