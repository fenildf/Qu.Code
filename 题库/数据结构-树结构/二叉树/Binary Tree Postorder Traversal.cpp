


// __________________________ Binary Tree Postorder Traversal __________________________
/*
题目来源:
https://leetcode.com/problems/binary-tree-postorder-traversal/
http://www.lintcode.com/zh-cn/problem/binary-tree-postorder-traversal/

二叉树的后序遍历
*/  


/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

*/

// __________________________ Tags __________________________
/*
	 
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用递归方法
// 时间复杂度O(n),空间复杂度O(1)。
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
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> nums;
        if (root == nullptr)return nums;
        
        vector<int> leftNums;
        vector<int> rightNums;

        
        if (root->left != nullptr) {
            leftNums = postorderTraversal(root->left);
            for (auto &item: leftNums) { //遍历容器中的各个成员！
                nums.push_back(item);
            } 
        }

        if (root->right != nullptr) {
            rightNums = postorderTraversal(root->right);
            for (auto &item: rightNums) { //遍历容器中的各个成员！
                nums.push_back(item);
            } 
        }
        
        nums.push_back(root->val);

        return nums;
    }
};


// 代码2 - 非递归方法-用栈-最后一个翻转，神来之笔，我自己都佩服自己能想出来。
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        stack<TreeNode *> stk;

        if(root != nullptr) stk.push(root);
        while(!stk.empty()) {
            root = stk.top();
            stk.pop();
            nums.push_back(root->val);
            
            if(root->left != nullptr) stk.push(root->left);
            if(root->right != nullptr) stk.push(root->right);
        }
        
        reverse(nums.begin(), nums.end());

        return nums;
    }
};