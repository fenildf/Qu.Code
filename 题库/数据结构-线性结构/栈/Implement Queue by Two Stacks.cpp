


// __________________________ Implement Queue by Two Stacks  __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/implement-queue-by-two-stacks/

*/  


/*
As the title described, you should only use two stacks to implement a queue's actions.

The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.

Both pop and top methods should return the value of first element.

Example
For push(1), pop(), push(2), push(3), top(), pop(), you should return 1, 2 and 2

Challenge
implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.

*/

// __________________________ Tags __________________________
/*
	 Stack;    Queue;
*/

// __________________________ 实现细节 __________________________ 

// 代码1   
// 时间复杂度O(n),空间复杂度O(1)
/*
    pop() 返回队首元素，并弹出;
    top() 返回队首元素，不弹出。
*/

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        
        stack1.push(element);
        
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    
    int pop() {
        int temp = stack2.top();
        stack2.pop();
        return temp;
    }

    int top() {
        return stack2.top();
    }
};    