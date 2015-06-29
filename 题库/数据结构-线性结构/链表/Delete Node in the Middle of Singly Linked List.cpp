


// __________________________ Delete Node in the Middle of Singly Linked List  __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/delete-node-in-the-middle-of-singly-linked-list/

*/  


/*
Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.


Example
Given 1->2->3->4, and node 3. return 1->2->4
*/

// __________________________ Tags __________________________
/*
	 Linked List
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(1),空间复杂度O(1)
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

