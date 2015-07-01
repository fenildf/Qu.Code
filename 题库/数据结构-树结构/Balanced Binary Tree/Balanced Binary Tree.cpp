


// __________________________ Balanced Binary Tree  __________________________
/*
题目来源:
https://leetcode.com/problems/balanced-binary-tree/
http://www.lintcode.com/zh-cn/problem/balanced-binary-tree/

平衡二叉树
*/  


/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the 
two subtrees of every node never differ by more than 1.

样例
给出二叉树 A={3,9,20,#,#,15,7}, B={3,#,20,15,7}

A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
二叉树A是高度平衡的二叉树，但是B不是12
*/

// __________________________ Tags __________________________
/*
	 递归
*/

// __________________________ 所用到的数据结构 __________________________
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// __________________________ 实现细节 __________________________ 
// 代码1 - 递归版
// 辅助空间-
// 
class Solution {
public:
    bool isBalanceTree = true; 
    bool isBalanced(TreeNode *root) {
        // write your code here
        maxDepth(root);
        return isBalanceTree;
    }
    
    int maxDepth(TreeNode *root) {
        // isBalanceTree 为 false,就不需要再递归运算了。
        if (root == nullptr || isBalanceTree == false) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        if (abs(left - right) > 1) isBalanceTree = false;
        
        return max(left, right) + 1;
    }
};