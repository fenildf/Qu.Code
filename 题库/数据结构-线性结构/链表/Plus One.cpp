


// __________________________66- Plus One  __________________________
/*
题目来源:

https://leetcode.com/problems/plus-one/
http://www.lintcode.com/en/problem/plus-one/#

*/  


/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example
Given [1,2,3] which represents 123, return [1,2,4].

Given [9,9,9] which represents 999, return [1,0,0,0].
*/

// __________________________ Tags __________________________
/*
	 Array,Math
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n),空间复杂度O(1)
/*
    输入 [] 也可以正常输出 [1]
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int carry = 1;                              // 进位的数
        
        for (int i = length - 1; i > -1 && carry != 0; --i) {
            int num = digits[i] + carry;
            digits[i] = num%10;
            carry = num/10;
        }
        
        if (carry != 0) digits.insert(digits.begin(), carry);   // 说明进位增加了。 原来3位的数组，现在4位了。
        return digits;
    }
};

