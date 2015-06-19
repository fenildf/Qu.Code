


// __________________________155- Min Stack  __________________________
/*
题目来源:

https://leetcode.com/problems/min-stack/
http://www.lintcode.com/en/problem/min-stack/

*/  


/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.



*/

// __________________________ Tags __________________________
/*
	 Stack;Data Structura;
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n),空间复杂度O(n)
/*
    
*/
class MinStack {
public:
    stack<int> stack1;
    stack<int> minstack;
    
    void push(int number) {
        stack1.push(number);
        if (!minstack.empty()) {
            number = minstack.top() > number ? number : minstack.top();
        } 
        minstack.push(number);
    }

    void pop() {
        stack1.pop();
        minstack.pop();
    }

    int top() {
        return stack1.top();
    }

    int getMin() {
        if (!minstack.empty()) return minstack.top();
        return 0;
    }
};


// __________________________ Solution __________________________ 
/*
Hints:

Consider space-time tradeoff. How would you keep track of the minimums using extra space?
Make sure to consider duplicate elements.
O(n) runtime, O(n) space – Extra stack:

Use an extra stack to keep track of the current minimum value. During the push operation we choose the new element or the current minimum, 
whichever that is smaller to push onto the min stack.

O(n) runtime, O(n) space – Minor space optimization:

If a new element is larger than the current minimum, we do not need to push it on to the min stack. When we perform the pop operation, 
check if the popped element is the same as the current minimum. If it is, pop it off the min stack too.

*/