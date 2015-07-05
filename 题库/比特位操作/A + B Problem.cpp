


// __________________________ A + B Problem  __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/a-b-problem/

*/  


/*
Write a function that add two numbers A and B. You should not use + or any arithmetic operators.


Example
Given a=1 and b=2 return 3

Note
There is no need to read data from standard input stream. 
Both parameters are given in function aplusb, you job is to calculate the sum and return it.

Challenge
Of course you can just return a + b to get accepted. But Can you challenge not do it like that?

Clarification
Are a and b both 32-bit integers?

Yes.
Can I use bit operation?

Sure you can.
*/

// __________________________ Tags __________________________
/*
	 Bit Manipulation 
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int cf = a & b;  
        int sum = a ^ b;  
  
        while (cf) {  
            a = sum;  
            b = cf << 1;  
            cf = a & b;  
            sum = a ^ b;  
        } 
        
        return sum;
    }
};

