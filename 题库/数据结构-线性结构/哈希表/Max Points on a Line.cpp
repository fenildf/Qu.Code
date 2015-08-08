


// __________________________ Copy List with Random Pointer __________________________
/*
题目来源:
https://leetcode.com/problems/copy-list-with-random-pointer/
http://www.lintcode.com/zh-cn/problem/copy-list-with-random-pointer/

复制带随机指针的链表
*/  


/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

// __________________________ Tags __________________________
/*
	 Linked List
*/

// __________________________ 所用到的数据结构 __________________________
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// __________________________ 实现细节 __________________________ 
// 代码1-这个深度复制就是乱搞，所有的随机指针都是一个新节点，并不是原先链表里的节点。然后居然通过测试了，只能说他们的数据太弱了。
// 时间复杂度O(n),额外空间复杂度O(1～n)。
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return nullptr;
        
        // 头节点
        RandomListNode * headNode = nullptr;
        RandomListNode * lastNode;
        RandomListNode * nowPrint  = head;
        
        // 一般复制
        while(nowPrint != nullptr){
            RandomListNode * nowNode = new RandomListNode(nowPrint->label);
            
            // 深度复制-乱搞
            if (nowPrint->random != nullptr) {
                RandomListNode * randomNode = new RandomListNode(nowPrint->random->label);
                nowNode->random = randomNode;
            }
            
            nowPrint = nowPrint->next;
            if (headNode == nullptr) {
                headNode = nowNode;
                lastNode = nowNode;
            } else {
                lastNode->next = nowNode;
                lastNode = lastNode->next;
            }
        }
        
        
        return headNode;
    }
};


// 代码2-使用1个map来记录走过的链表。哈希表。
// 时间复杂度O(n),额外空间复杂度O(1～n)。
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (head == nullptr) return nullptr;
        
        // 哈希映射表
        map<RandomListNode*, RandomListNode*> oldNewPtrs;
        
        // 头节点
        RandomListNode * headNode = nullptr;
        RandomListNode * lastNode;
        RandomListNode * nowPrint  = head;
        
        // 一般复制
        while(nowPrint != nullptr) {
            RandomListNode * nowNode = new RandomListNode(nowPrint->label);
            
            oldNewPtrs[nowPrint] = nowNode;
            
            nowPrint = nowPrint->next;
            if (headNode == nullptr) {
                headNode = nowNode;
                lastNode = nowNode;
            } else {
                lastNode->next = nowNode;
                lastNode = lastNode->next;
            }
        }
        
        // 深度复制
        nowPrint  = head;
        while(nowPrint != nullptr) { 
            if (nowPrint->random != nullptr) {
                oldNewPtrs[nowPrint]->random = oldNewPtrs[nowPrint->random];
            }
            
            nowPrint = nowPrint->next;
        }
        
        return headNode;
    }
};
