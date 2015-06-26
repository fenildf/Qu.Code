


// __________________________ Lowest Common Ancestor __________________________
/*
题目来源:
https://leetcode.com/problems/validate-binary-search-tree/
http://www.lintcode.com/zh-cn/problem/validate-binary-search-tree/

验证二叉查找树
*/  


/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

1-The left subtree of a node contains only nodes with keys less than the node's key.
2-The right subtree of a node contains only nodes with keys greater than the node's key.
3-Both the left and right subtrees must also be binary search trees.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

给定一个二叉树，判断它是否是合法的二叉查找树(BST)
一棵BST定义为：

节点的左子树中的值要严格小于该节点的值。
节点的右子树中的值要严格大于该节点的值。
左右子树也必须是二叉查找树。
*/

// __________________________ Tags __________________________
/*
	 Tree, Depth-first Search
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
// 传递的值，需要把最大，最小值都传递回来才行，然后进行对比。

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isBST; 
    bool isValidBST(TreeNode *root) {
        // write your code here
        isBST = true;
        compare(root, 0);
        return isBST;
    }
    
    /*
        i:  0-说明是左子树，返回左子树节点中max的值; 
            1-说明是右子树，返回右子树节点中min的值; 
    */ 
    int compare(TreeNode *root,int i) {
        // write your code here
        if(root == nullptr)return 0;
        int mid = root->val;
        
        if (root->left != nullptr) 
        {
            int left = compare(root->left, 0);
            if (left >= root->val) isBST = false;
            if (i == 1) mid = left;
        }
        
        if (root->right != nullptr) 
        {
            int right = compare(root->right, 1);
            if (right <= root->val) isBST = false;
            if (i == 0) mid = right;
        }
            
        return mid;
    }
};