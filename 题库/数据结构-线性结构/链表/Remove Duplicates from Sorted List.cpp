


// __________________________ Remove Duplicates from Sorted List   __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list/
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

*/  


/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

// __________________________ Tags __________________________
/*
	 Linked List
*/


// __________________________ 所用到的数据结构 __________________________
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *nowNode = head;
        while (nowNode != nullptr) {
            if(nowNode->next != nullptr && nowNode->next->val == nowNode->val) {
                nowNode->next = nowNode->next->next;
            } else {
                nowNode = nowNode->next;
            }
        }
        
        return head;
    }
};

