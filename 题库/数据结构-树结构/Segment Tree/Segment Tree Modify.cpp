


// __________________________ Segment Tree Modify __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/segment-tree-modify/

线段树的查询
*/  


/*
For a Maximum Segment Tree, which each node has an extra value max to store the maximum value in this node's interval.

Implement a modify function with three parameter root, index and value to change the node's value with [start, end] = [index, index] to the new given value. Make sure after this change, every node in segment tree still has the max attribute with the correct value.


Example
For segment tree:

                      [1, 4, max=3]
                    /                \
        [1, 2, max=2]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=3]
if call modify(root, 2, 4), we can get:

                      [1, 4, max=4]
                    /                \
        [1, 2, max=4]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=4], [3, 3, max=0], [4, 4, max=3]
or call modify(root, 4, 0), we can get:

                      [1, 4, max=2]
                    /                \
        [1, 2, max=2]                [3, 4, max=0]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=0]
Note
We suggest you finish problem Segment Tree Build and Segment Tree Query first.

Challenge
Do it in O(h) time, h is the height of the segment tree.
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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    int modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        
        // 走到叶子节点。 
        if(index == root->start && index == root->end) {
            root->max = value;
            return root->max;
        }
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        int retLeft,retRight;
        if (index <= leftEnd) {
            retLeft = modify(root->left, index, value);
            retRight = root->right->max;
        }
        
        if (index >= rightStart) {
            retRight = modify(root->right, index, value);
            retLeft = root->left->max;
        }
        
        root->max = max(retLeft, retRight);
        
        return root->max;
    }
};
