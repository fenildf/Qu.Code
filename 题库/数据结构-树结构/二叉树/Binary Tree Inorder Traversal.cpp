


// __________________________ Binary Tree Inorder Traversal __________________________
/*
题目来源:
https://leetcode.com/problems/binary-tree-inorder-traversal/
http://www.lintcode.com/zh-cn/problem/binary-tree-inorder-traversal/

二叉树的中序遍历
*/  


/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> nums;
        if (root == nullptr)return nums;
        
        vector<int> leftNums;
        vector<int> rightNums;

        
        if (root->left != nullptr) {
            leftNums = inorderTraversal(root->left);
            for (auto &item: leftNums) { //遍历容器中的各个成员！
                nums.push_back(item);
            } 
        }

        nums.push_back(root->val);
        
        if (root->right != nullptr) {
            rightNums = inorderTraversal(root->right);
            for (auto &item: rightNums) { //遍历容器中的各个成员！
                nums.push_back(item);
            } 
        }
        
        return nums;
    }
};


// 代码2 - 非递归方法-用栈-用栈模拟递归的函数调用就可以了。
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
