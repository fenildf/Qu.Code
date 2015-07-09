


// __________________________ Rotate List __________________________
/*
题目来源:
https://leetcode.com/problems/rotate-list/
http://www.lintcode.com/zh-cn/problem/rotate-list/

旋转链表
*/  


/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
// 代码1-
// 时间复杂度O(2n),空间复杂度O(1)。
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode * headNode = new ListNode(0);          // 用于返回的头结点
        headNode->next = head;
        ListNode * first = head;
        ListNode * second = head;
        

        int i = 1;      // 统计节点的个数
        while(first->next != nullptr) {
            ++i;
            first = first->next;
        }
        
        k = k%i;        // 第2个指针开始往右 移动k步
        if(k == 0) return head;
        while(i - k > 1){
            second = second->next;
            ++k;
        }
        
        headNode->next = second->next;
        second->next = nullptr;
        first->next = head;
        
        return headNode->next;
    }
};