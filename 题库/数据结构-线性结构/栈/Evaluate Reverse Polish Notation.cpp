


// __________________________ 150 - Evaluate Reverse Polish Notation  __________________________
/*
题目来源:

https://leetcode.com/problems/evaluate-reverse-polish-notation/
http://www.lintcode.com/en/problem/evaluate-reverse-polish-notation/

*/  


/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

// __________________________ Tags __________________________
/*
	 Stack;
*/

// __________________________ 实现细节 __________________________ 

// 代码1-自己写的时候都感觉很罗嗦。
// 时间复杂度O(n),空间复杂度O(1)
/*
   提示说 用队列来做，但是发现 用 栈 才能做出来。
*/
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> q;
        
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                int num1 = q.top();
                q.pop();
                int num2 = num1 + q.top();
                q.pop();
                q.push(num2);
            } else if(tokens[i] == "-") {
                int num1 = q.top();
                q.pop();
                int num2 = q.top() - num1;
                q.pop();
                q.push(num2);
            } else if(tokens[i] == "*") {
                int num1 = q.top();
                q.pop();
                int num2 = num1 * q.top();
                q.pop();
                q.push(num2);
            } else if(tokens[i] == "/") {
                int num1 = q.top();
                q.pop();
                int num2 = q.top() / num1;
                q.pop();
                q.push(num2);
            } else {
                q.push(atoi(tokens[i].c_str())); 
            }
        }
        
        return q.top() ;
    }
};


// 代码2-抽出一个函数来判断
// 时间复杂度O(n),空间复杂度O(1)
/*
   
*/
class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> q;
        
        for (int i = 0; i < tokens.size(); ++i) {
            if (is_operator(tokens[i])) {
                int num1 = q.top();
                q.pop();
                int num2 = q.top();
                q.pop();
                if (tokens[i] == "+") q.push(num2 + num1);
                if (tokens[i] == "-") q.push(num2 - num1);
                if (tokens[i] == "*") q.push(num2 * num1);
                if (tokens[i] == "/") q.push(num2 / num1);
            } else {
                q.push(atoi(tokens[i].c_str())); 
            }
        }
        return q.top() ;
    }
    
    bool is_operator(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/") ;
    }
};