


// __________________________ Reverse Linked List  __________________________
/*
题目来源:
https://leetcode.com/problems/reverse-linked-list/
http://www.lintcode.com/zh-cn/problem/reverse-linked-list/

翻转链表
*/  


/*
Reverse a singly linked list.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode * nowNode = head->next;
        ListNode * prevNode = head;
        ListNode * nextNode = nowNode->next;
        prevNode->next = nullptr;
        
        while (nowNode != nullptr) {
            nowNode->next = prevNode;
            
            prevNode = nowNode;
            nowNode = nextNode;
            if(nextNode != nullptr) nextNode = nextNode->next;
        }
        
        return prevNode;
    }
};


// 代码2-递归版本
