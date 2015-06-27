


// __________________________ Binary Tree Level Order Traversal  __________________________
/*
题目来源:
https://leetcode.com/problems/binary-tree-level-order-traversal/
http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal/

二叉树的层次遍历
*/  


/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},    // 这种写法是完全二叉树的写法。

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

// __________________________ Tags __________________________
/*
	 Tree,Breadth-first Search
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
// 代码1 - 使用迭代方法
// 辅助空间-两个栈

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // write your code here
        vector<vector<int>> matrix;
        if (root == nullptr)return matrix;

        stack<TreeNode *> stk;
        stack<int> deepS;
        
        if(root != nullptr) stk.push(root);
        deepS.push(1);

        while(!stk.empty()) {
            root = stk.top();
            stk.pop();
            
            int deep = deepS.top();
            deepS.pop();

// --------------------------------------------- 
    /* 在寻找最大深度的那个题目上加如下代码即可*/ 
            if (deep > matrix.size()) {
                vector<int> line;
                matrix.push_back(line);
            }
            matrix[deep-1].push_back(root->val);
// ---------------------------------------------  

            if(root->right != nullptr) {
                stk.push(root->right);
                deepS.push(deep + 1);   
            }
            if(root->left != nullptr) {
                stk.push(root->left);
                deepS.push(deep + 1);
            } 
        }
        
        
        return matrix;
    }
};


// 代码2 - 递归版-
/*
    而且只能从顶往下递归，绝对不能从脚往头递归，要不然不知道是第几行了。

*/ 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> matrix;
    
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        if (root == nullptr)return matrix;
        dig(root,1);
        
        return matrix;
    }
    
    void dig(TreeNode *root,int deep) {
// --------------------------------------------- 
    /* 在寻找最大深度的那个题目上加如下代码即可*/         
        if (deep > matrix.size()) matrix.push_back(vector<int> ());     // 如果超过容器大小, 添加一个空的容器进去

        matrix[deep-1].push_back(root->val);
// ---------------------------------------------  

        if (root->left != nullptr) dig(root->left,deep+1); 
        if (root->right != nullptr) dig(root->right,deep+1);
    }
};


// 代码3 - 使用迭代方法
// 辅助空间-只用1个队列
 