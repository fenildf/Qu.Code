


// __________________________ Merge Two Sorted Lists __________________________
/*
题目来源:
https://leetcode.com/problems/merge-two-sorted-lists/
http://www.lintcode.com/zh-cn/problem/merge-two-sorted-lists/

合并两个排序链表
*/  


/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/

// __________________________ Tags __________________________
/*
	 Linked List
*/

// __________________________ 所用到的数据结构 __________________________
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

// __________________________ 实现细节 __________________________ 
// 代码1-新建一个链表，不修改原有链表的基础上。
// 在合并 K个链表的时候 就不能这样了。会生成一堆长链表丢失在内存中，会被报 Memory Limit Exceeded 错误。
// 时间复杂度O(max(n,m)),空间复杂度O(n+m)。
// 这里用到的是插入排序 
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        
        ListNode * head = new ListNode(0);
        ListNode * nowNode = head;
        while(l1 != nullptr || l2 != nullptr) {
            int pushValue;
            
            if (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    pushValue = l1->val;
                    l1 = l1->next;
                } else {
                    pushValue = l2->val;
                    l2 = l2->next;
                }
            } else if (l1 != nullptr) {
                pushValue = l1->val;
                l1 = l1->next;
            } else {
                pushValue = l2->val;
                l2 = l2->next;
            }
            
            nowNode->next = new ListNode(pushValue);
            nowNode = nowNode->next;
        }
        
        return head->next;
    }
};


// 代码2-
