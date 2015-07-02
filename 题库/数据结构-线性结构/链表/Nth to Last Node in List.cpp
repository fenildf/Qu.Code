


// __________________________ Nth to Last Node in List __________________________
/*
题目来源:
https://leetcode.com/problems/reverse-linked-list/
http://www.lintcode.com/zh-cn/problem/reverse-linked-list/

翻转链表
*/  


/*
Find the nth to last element of a singly linked list. 

The minimum number of nodes in list is n.

Example
Given a List  3->2->1->5->null and n = 2, return node  whose value is 1.
*/

// __________________________ Tags __________________________
/*
	 Linked List
*/

// __________________________ 实现细节 __________________________ 
// 代码1-迭代版本
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode *first = head;
        ListNode *second = head;
        
        while(n != 0) {
            first = first->next;
            --n;
        }
        
        while(first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        return second;
    }
};


// 代码2-
