


// __________________________ Maximum Depth of Binary Tree __________________________
/*
题目来源:
https://leetcode.com/problems/maximum-depth-of-binary-tree/
http://www.lintcode.com/zh-cn/problem/maximum-depth-of-binary-tree/

二叉树的最大深度
*/  


/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


*/

// __________________________ Tags __________________________
/*
	 
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用递归方法
// 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int deepMax; 
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr)return 0;
        
        deepMax = 1;
        dig(root,1);
        return deepMax;
    }
    
    void dig(TreeNode *root,int deep) {
        deepMax = max(deep, deepMax);
        if (root->left != nullptr) dig(root->left,deep+1); 
        if (root->right != nullptr) dig(root->right,deep+1);
    }
};

// 代码2 - 使用递归方法-超级简洁
// 时间复杂度O(n),空间复杂度O(n)。
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 代码3 - 非递归方法-用栈-
// 时间复杂度O(n),空间复杂度O(n)。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr)return 0;
        int deepMax = 1;
        
        stack<TreeNode *> stk;
        stack<int> deepS;
        
        if(root != nullptr) stk.push(root);
        deepS.push(1);
        
        while(!stk.empty()) {
            root = stk.top();
            stk.pop();
            
            int deep = deepS.top();
            deepS.pop();
            
            deepMax = max(deep, deepMax);
            if(root->right != nullptr) {
                stk.push(root->right);
                deepS.push(deep + 1);   
            }
            if(root->left != nullptr) {
                stk.push(root->left);
                deepS.push(deep + 1);
            } 
        }
        return deepMax;
    }
};