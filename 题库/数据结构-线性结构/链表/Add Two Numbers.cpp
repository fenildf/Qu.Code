


// __________________________ Add Two Numbers   __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/add-two-numbers/
https://leetcode.com/problems/add-two-numbers/

*/  


/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1,num2,num3;
        int Carry = 0;
        ListNode head(-1);
        ListNode *nextNode = &head;
        
        while (l1 != nullptr || l2 != nullptr) {
            num1 = (l1 != nullptr) ? l1->val : 0;
            num2 = (l2 != nullptr) ? l2->val : 0;
            
            num3 = (num1 + num2 + Carry)%10;
            Carry = (num1 + num2 + Carry)/10;
            

            nextNode->next = new ListNode(num3);
            nextNode = nextNode->next;
            
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        
        if (Carry != 0) {
            nextNode->next = new ListNode(Carry);
            nextNode = nextNode->next;
        }
        
        return head.next;
    }
};

