


// __________________________ Merge k Sorted Lists __________________________
/*
题目来源:
https://leetcode.com/problems/merge-k-sorted-lists/
http://www.lintcode.com/zh-cn/problem/merge-k-sorted-lists/

合并k个排序链表
*/  


/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
// 代码1-在l1 基础上进行修改。 把 l2 插入到 l1 中，这样节省内存。
// 内存是保证不会超了，但是每次插入都会在链表里面去找要插入的点，会导致插入时间会越来越长，最终超时。见代码2的改进。
// 时间复杂度O(n^2),空间复杂度O(n)。
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.size() == 0) return (ListNode *)nullptr;
        
        ListNode * ret = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            ret = mergeTwoLists(ret, lists[i]);
        }
        
        return ret;
    }
    
    
    // 为合并 K 个链表做的特殊处理，在l1 基础上进行修改。 把 l2 插入到 l1 中，这样节省内存。
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        
        ListNode * head = new ListNode(0);
        ListNode * nowNode = head;
        
        head->next = l1;
        
        while(l2 != nullptr) {
            if (nowNode->next == nullptr || l2->val <= nowNode->next->val) {
                ListNode * insert = new ListNode(l2->val);
                insert->next = nowNode->next;
                nowNode->next = insert;
                l2 = l2->next;
            }
            nowNode = nowNode->next;
        }
    
        return head->next;
    }
};


// 代码2-
// 时间复杂度O(log(n)),空间复杂度O(n)。
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.size() == 0) return (ListNode *)nullptr;
        
        // 把所有值取出来放入一个池子里。
        vector<int> pool;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode * ret = lists[i];
            while(ret != nullptr) {
                pool.push_back(ret->val);
                ret = ret->next;
            }
        }
        
        // 对池子进行排序
        sort(pool.begin(), pool.end());     
        
        // 把池子里的值全部取出来变成链表。
        ListNode * head = new ListNode(0);  
        ListNode * nowNode = head;
        for(int i = 0; i < pool.size(); ++i) {
            nowNode->next = new ListNode(pool[i]);
            nowNode = nowNode->next;
        }
        
        return head->next;
    }
};