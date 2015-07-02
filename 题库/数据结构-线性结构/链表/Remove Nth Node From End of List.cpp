


// __________________________ Remove Nth Node From End of List __________________________
/*
题目来源:
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
http://www.lintcode.com/zh-cn/problem/remove-nth-node-from-end-of-list/

删除链表中倒数第n个节点
*/  


/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5->null, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5->null.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head;
        ListNode *delNode = head;
        ListNode *foreNode = new ListNode(-1);  // 指向delNode 前一个节点
        foreNode->next = head;
        
        while(n != 0) {
            first = first->next;
            --n;
        }
        
        while(first != nullptr) {
            first = first->next;
            foreNode = delNode;
            delNode = delNode->next;
        }
        
        if (delNode == head) {
            head = head->next;
        } else {
            foreNode->next = delNode->next;
        }
        

        return head;
    }
};


// 代码2-
