


// __________________________ O(1) Check Power of 2  __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/o1-check-power-of-2/

*/  


/*
Using O(1) time to check whether an integer n is a power of 2.

Example：
For n=4, return true;

For n=5, return false;

Challenge：
    O(1) time
*/

// __________________________ Tags __________________________
/*
	 Bit Manipulation
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(1),空间复杂度O(1)

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if (n < 1) return false;
        return !(n & (n-1));
    }
};