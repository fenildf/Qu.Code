


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
        // 边界检侧
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *ffNode = head;
        ListNode *foreNode = head;
        ListNode *nowNode = head->next;
        head = nullptr;
        
        bool checkhead = false;
        bool delFor = false;
        
        while (nowNode != nullptr) {
            if(foreNode->val == nowNode->val) {
                delFor = true;
                nowNode = nowNode->next;
                foreNode->next = nowNode;
                ffNode->next = nowNode; 
            } else {
                if (delFor == false) {
                    if (checkhead == false) {
                        checkhead = true;
                        head = foreNode;
                    }
                    
                    ffNode = foreNode;
                    foreNode = nowNode;
                    nowNode = nowNode->next;
                } else {        // 把 foreNode 删除了。
                    delFor = false;
                    ffNode->next = nowNode;
                    foreNode = nowNode;
                    nowNode = nowNode->next;
                }
                
            }
        }
        
        return head;
    }
};

