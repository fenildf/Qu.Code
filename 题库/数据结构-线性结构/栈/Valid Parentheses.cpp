


// __________________________20- Valid Parentheses  __________________________
/*
题目来源:

https://leetcode.com/problems/valid-parentheses/
http://www.lintcode.com/en/problem/valid-parentheses/

*/  


/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

Example：
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not..

*/

// __________________________ Tags __________________________
/*
	 Stack;
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n),空间复杂度O(1)
/*
    输入 [] 也可以正常输出 [1]
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
                continue;
            } 

            if (stk.empty()) return false;  // input: "]"
            if ((stk.top() == '(' && s[i] == ')') || (stk.top() == '{' && s[i] == '}') || (stk.top() == '[' && s[i] == ']')) {
                stk.pop();  
            } else {
                return false;
            }
            
        }
        
        if (stk.empty()) return true;
        return false;
    }
};
