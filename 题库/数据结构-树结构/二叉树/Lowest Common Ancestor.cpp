


// __________________________ Lowest Common Ancestor __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/lowest-common-ancestor/

二叉树的层次遍历 II
*/  


/*
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.


Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6
LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7
*/

// __________________________ Tags __________________________
/*
	 LintCode 自己出的题目...
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
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *target; 
    bool init;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        target = nullptr;
        findNode(root,A,B);
        return target;
    }
    
    int findNode(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if (root == nullptr) return 0;
        int temp = 0;
        if (root == A) temp += 1;       //预防这种输入：{1}, 1, 1
        if (root == B) temp += 1;
        temp += findNode(root->left,A,B) + findNode(root->right,A,B);
        
        if (temp == 2 && target == nullptr) target = root;
            
        return temp;
    }
};