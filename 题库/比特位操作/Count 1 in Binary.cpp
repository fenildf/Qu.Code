


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
// 时间复杂度O(k),空间复杂度O(1)  // k 的值为 1～32.
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
// 时间复杂度O(m),空间复杂度O(1)  // m 的值为 1的个数
// 满足挑战要求：If the integer is n bits with m 1 bits. Can you do it in O(m) time?
class Solution {
public:

    int countOnes(int num) {
        int one_num = 0;
        
        while (num != 0) {      // 把所有的1都变成0了，就跳出循环。
            ++one_num;
            num = num & (num - 1);  // 把最低位的1变成0了。
        }
        
        return one_num;
    }
};

/*   _____________ num = num & (num - 1) 的技巧 _____________ 
    这个就是 把 num 的最低位的 1变成0。
    位运算中经常要用到的技巧。
*/


/*  _____________ 负数的情况 _____________ 
    如果 num = 32(10 0000),输出应该是 1
    当时如果我把 num 改为 -32(1111 1111 。。。 。。。 1110 0000)，输出就是 27
    所有这个方程也能够计算负数。
*/

/*  _____________ 延伸情况 _____________
    01-统计0的个数：先算1的个数，再用 32 - （1的个数）
    02-
*/


