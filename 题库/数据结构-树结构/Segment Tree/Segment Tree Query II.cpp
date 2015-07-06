


// __________________________ Segment Tree Query II __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/segment-tree-query-ii/

线段树查询 II
*/  


/*
For an array, we can build a SegmentTree for it, each node stores an extra attribute count to denote the number of elements in the the array which value is between interval start and end. (The array may not fully filled by elements)

Design a query method with three parameters root, start and end, find the number of elements in the in array's interval [start, end] by the given root of value SegmentTree.

Example
For array [0, 2, 3], the corresponding value Segment Tree is:

                     [0, 3, count=3]
                     /             \
          [0,1,count=1]             [2,3,count=2]
          /         \               /            \
   [0,0,count=1] [1,1,count=0] [2,2,count=1], [3,3,count=1]

query(1, 1), return 0

query(1, 2), return 1

query(2, 3), return 2

query(0, 2), return 2
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
// 就是比  线段树查询 I 的最大值，变化成 和。然后注意 输入值的判断。
// 
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        // 越界判断
        if(root == nullptr || start > root->end || end < root->start) return 0;
        
        // 重定范围
        if(start < root->start) start = root->start;
        if(end > root->end) end = root->end;
        
        if(start == root->start && end == root->end) return root->count;
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        int maxret = 0;
        if (end <= leftEnd) maxret = query(root->left, start, end);
        
        if (start >= rightStart) maxret = query(root->right, start, end);
        
        if (start < rightStart && end > leftEnd) {
            maxret = query(root->left, start, leftEnd) + query(root->right, rightStart, end);
        }
        
        return maxret;
    }
};