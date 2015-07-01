


// __________________________ Remove Duplicates from Sorted List II   __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list-ii/
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

*/  


/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
    
        
        ListNode *foreNode = head;
        ListNode *nowNode = foreNode;
        ListNode *nextNode = foreNode->next;
        
        ListNode *saveNode = nullptr; 
                      head = nullptr;
        
        while (nextNode != nullptr) {
            if(nextNode->val == nowNode->val) {
                nowNode = nextNode;
                nextNode = nextNode->next;
            } else if (nextNode->val != nowNode->val) {
                
                if (nowNode == foreNode) {
                    if (saveNode == nullptr) {
                        saveNode = foreNode;
                        head = foreNode;
                    } else {
                        saveNode->next->val = foreNode->val;
                        saveNode = saveNode->next;
                    }
                }
                
                foreNode = nextNode;
                nowNode = nextNode;
                nextNode = foreNode->next;
            }
        }
        
        if(foreNode == nowNode && saveNode != nullptr) {
            saveNode->next->val = foreNode->val;
            saveNode = saveNode->next;
        } else if (foreNode == nowNode && saveNode == nullptr) {
            head = foreNode;
            head->next = nullptr;
        }
        
        if (saveNode != nullptr) {
            saveNode->next = nullptr;
        }
        
        return head;
    }
};
