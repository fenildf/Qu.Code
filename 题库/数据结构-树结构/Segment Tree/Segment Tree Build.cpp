


// __________________________ Segment Tree Build __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/segment-tree-build/

线段树的构造
*/  


/*
The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.

start and end are both integers, they should be assigned in following rules:

The root's start and end is given by build method.
The left child of node A has start=A.left, end=(A.left + A.right) / 2.
The right child of node A has start=(A.left + A.right) / 2 + 1, end=A.right.
if start equals to end, there will be no children for this node.
Implement a build method with two parameters start and end, so that we can create a corresponding segment tree with every node has the correct start and end value, return the root of this segment tree.


Example
Given start=0, end=3. The segment tree will be:

               [0,  3]
             /        \
      [0,  1]           [2, 3]
      /     \           /     \
   [0, 0]  [1, 1]     [2, 2]  [3, 3]
Given start=1, end=6. The segment tree will be:

               [1,  6]
             /        \
      [1,  3]           [4,  6]
      /     \           /     \
   [1, 2]  [3,3]     [4, 5]   [6,6]
   /    \           /     \
[1,1]   [2,2]     [4,4]   [5,5]

Clarification

Segment Tree (a.k.a Interval Tree) is an advanced data structure which can support queries like:

which of these intervals contain a given point
which of these points are in a given interval

See wiki: Segment Tree Interval Tree
*/

// __________________________ Tags __________________________
/*
	 Binary Tree, Segment Tree
*/

// __________________________ 所用到的数据结构 __________________________
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// __________________________ 实现细节 __________________________ 
// 代码1 - 递归构造。
// 
// 
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start > end) return (SegmentTreeNode *)nullptr;    // 排序树，start <= end
        
        SegmentTreeNode *  newNode  = new SegmentTreeNode(start, end);
        if (start == end) return newNode;
        
        int leftEnd = (start + end) / 2 ;
        int rightStart = (start + end) / 2 + 1;
        newNode->left   = build(start, leftEnd);
        newNode->right  = build(rightStart, end);
        
        return newNode;
    }
};