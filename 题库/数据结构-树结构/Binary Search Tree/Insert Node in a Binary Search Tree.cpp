


// __________________________ Insert Node in a Binary Search Tree __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/insert-node-in-a-binary-search-tree/

验证二叉查找树
*/  


/*
Given a binary search tree and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.

Have you met this question in a real interview? Yes
Example
Given binary search tree as follow, after Insert node 6, the tree should be:

  2             2
 / \           / \
1   4   -->   1   4
   /             / \ 
  3             3   6
Challenge
Can you do it without recursion?
*/

// __________________________ Tags __________________________
/*
	 BST,lintCode 自己出的题目。
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
// 

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (root == nullptr) return node;
        
        int mid = root->val;
        int nums = node->val;
        if(nums > mid) {
            if (root->right != nullptr) {
                insertNode(root->right,  node);
            } else {
                root->right = node;
            }
        } else if (nums < mid) {
            if (root->left != nullptr) {
                insertNode(root->left,  node);
            } else {
                root->left = node;
            }
        }
        
        return root;
    }
};