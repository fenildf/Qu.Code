


// __________________________ Segment Tree Query __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/segment-tree-query/

线段树的查询
*/  


/*
Medium Segment Tree Query

34% Accepted
For an integer array (index from 0 to n-1, where n is the size of this array), in the corresponding SegmentTree, each node stores an extra attribute max to denote the maximum number in the interval of the array (index from start to end).

Design a query method with three parameters root, start and end, find the maximum number in the interval [start, end] by the given root of segment tree.


Example
For array [1, 4, 2, 3], the corresponding Segment Tree is:

                  [0, 3, max=4]
                 /             \
          [0,1,max=4]        [2,3,max=3]
          /         \        /         \
   [0,0,max=1] [1,1,max=4] [2,2,max=2], [3,3,max=3]

query(root, 1, 1), return 4

query(root, 1, 2), return 4

query(root, 2, 3), return 3

query(root, 0, 2), return 4

Note
It is much easier to understand this problem if you finished Segment Tree Build first.
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
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// __________________________ 实现细节 __________________________ 
// 代码1 - 
// 
// 
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        // 越界判断
        if(root == nullptr || start > root->end || end < root->start) return 0;     // 优先判断 root 是否为 nullptr
        
        // 重定范围
        if(start < root->start) start = root->start;
        if(end > root->end) end = root->end;
        
        if(start == root->start && end == root->end) return root->max;
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        int maxret = 0;
        if (end <= leftEnd) maxret = query(root->left, start, end);
        
        if (start >= rightStart) maxret = query(root->right, start, end);
        
        if (start < rightStart && end > leftEnd) {
            maxret = max(query(root->left, start, leftEnd), query(root->right, rightStart, end));
        }
        
        return maxret;
    }
};