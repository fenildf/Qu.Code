


// __________________________ Flip Bits __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/flip-bits/

*/  


/*
Determine the number of bits required to flip if you want to convert integer n to integer m.

Have you met this question in a real interview? Yes
Example
Given n = 31 (11111), m = 14 (01110), return 2.

Note
Both n and m are 32-bit integers.
*/

// __________________________ Tags __________________________
/*
	 Bit Manipulation
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int c = a^b;    // 两数不相同的地方全都变成1，相同的地方全都变成0.
        int num = 0;
        
        // 统计 C中 位数 中 1的个数。
        while (c != 0) {
            c = c & (c-1);
            ++num;
        }
        return num;
    }
};

