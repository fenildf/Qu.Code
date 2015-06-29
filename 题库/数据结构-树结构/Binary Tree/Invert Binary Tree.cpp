


// __________________________ Invert Binary Tree __________________________
/*
题目来源:
https://leetcode.com/problems/invert-binary-tree/
http://www.lintcode.com/zh-cn/problem/invert-binary-tree/

知乎热议讨论帖：http://www.zhihu.com/question/31202353?rf=31187043

翻转二叉树
*/  


/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), 
but you can’t invert a binary tree on a whiteboard so fuck off.

*/

// __________________________ Tags __________________________
/*
	 Tree,
*/

// __________________________ 所用到的数据结构 __________________________
 /**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

// __________________________ 实现细节 __________________________ 
// 代码1 - 递归版
// 辅助空间-

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};