


// __________________________ Count 1 in Binary __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/count-1-in-binary/

*/  


/*
Count how many 1 in binary representation of a 32-bit integer.

Example
Given 32(100000), return 1

Given 5(101), return 2

Given 1023 (111111111), return 9

Challenge：
    If the integer is n bits with m 1 bits. Can you do it in O(m) time?
*/

// __________________________ Tags __________________________
/*
	 Bit Manipulation , Binary
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(32),空间复杂度O(1)
class Solution {
public:

    int countOnes(int num) {
        int one_num = 0;
        for (int i = 0; i < 32; ++i) {
            if ( num & (1<<i)) ++one_num;
        }
        return one_num;
    }
};

// 代码2
// 时间复杂度O(m),空间复杂度O(1)  // m 的值为 1～32.
// 满足挑战要求：If the integer is n bits with m 1 bits. Can you do it in O(m) time?
class Solution {
public:

    int countOnes(int num) {
        int one_num = 0;
        for (int i = 0; i < 32; ++i) {
            if ( num & (1<<i)) ++one_num;
            if ( num - (1<<(i+1)) < 0) break;     // 保证 高1位没有，就为负数。
        }
        return one_num;
    }
};

// 代码3
