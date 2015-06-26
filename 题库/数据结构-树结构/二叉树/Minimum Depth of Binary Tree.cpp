


// __________________________ Maximum Depth of Binary Tree __________________________
/*
题目来源:
https://leetcode.com/problems/maximum-depth-of-binary-tree/
http://www.lintcode.com/zh-cn/problem/maximum-depth-of-binary-tree/

二叉树的最小深度
*/  


/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


*/

// __________________________ Tags __________________________
/*
	 
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用递归方法-超级简洁
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
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        // 必须是到子节点的距离，如果是非子叶点，就不计算。
        return ((left*right == 0) ? max(left, right) : min(left, right)) + 1;
    }
};

// 代码2 - 非递归方法-用栈-
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
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr)return 0;
        int deepMin = 1;
        
        stack<TreeNode *> stk;
        stack<int> deepS;
        
        if(root != nullptr) stk.push(root);
        deepS.push(1);
        
        while(!stk.empty()) {
            root = stk.top();
            stk.pop();
            
            int deep = deepS.top();
            deepS.pop();
            
            if(root->right != nullptr) {
                stk.push(root->right);
                deepS.push(deep + 1);   
            }
            if(root->left != nullptr) {
                stk.push(root->left);
                deepS.push(deep + 1);
            } 
            
            // 只有没有左右子节点的节点才进入计算。
            if(root->left == nullptr && root->right == nullptr) {
                deepMin = (deepMin == 1) ? deep : min(deepMin, deep) ;
            }
        }
        return deepMin;
    }
};


// 代码3-迭代版-深度控制-剪枝