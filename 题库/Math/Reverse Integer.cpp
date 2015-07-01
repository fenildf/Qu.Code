


// __________________________ Reverse Integer   __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/reverse-integer/
https://leetcode.com/problems/reverse-integer/

*/  


/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

// __________________________ Tags __________________________
/*
	 Math
*/


// __________________________ 所用到的数据结构 __________________________
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(2*(1~32))),空间复杂度O(1~32)
class Solution {
public:
    int reverse(int n) {
        long nums = 0;
        stack<int> pool;
        while(n != 0) {
            pool.push(n%10);
            n /= 10;
        }
        
        int carry = 0;
        while(!pool.empty()) {
            long a = pool.top();
            pool.pop();
            a *= pow(10,carry++);
            
            nums += a;
        }
        
        if (nums > 2147483647 || nums < -2147483648) return 0;
        
        return (int)nums;
    }
};

