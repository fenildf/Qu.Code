


// __________________________ Binary Tree Preorder Traversal __________________________
/*
题目来源:
https://leetcode.com/problems/binary-tree-preorder-traversal/
http://www.lintcode.com/zh-cn/problem/binary-tree-preorder-traversal/

二叉树的前序遍历
*/  


/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> nums;
        if (root == NULL)return nums;
        
        vector<int> leftNums;
        vector<int> rightNums;

        nums.push_back(root->val);
        if (root->left != NULL) {
            leftNums = preorderTraversal(root->left);
            for (auto &item: leftNums) { //遍历容器中的各个成员！
                nums.push_back(item);
            } 
        }

        if (root->right != NULL) {
            rightNums = preorderTraversal(root->right);
            for (auto &item: rightNums) { //遍历容器中的各个成员！
                nums.push_back(item);
            } 
        }

        return nums;
    }
};

// 代码2 - 非递归方法-用栈
// 时间复杂度O(n),空间复杂度O(n)。
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> nums;
        stack<TreeNode *> stk;

        while(root != nullptr) {
            nums.push_back(root->val);
            if(root->right != nullptr) stk.push(root->right);

            if (root->left != nullptr) {
                root = root->left;
            } else if (!stk.empty()){
                root = stk.top();
                stk.pop();
            } else {
                break;
            }
        }

        return nums;
    }
};

// 代码3 - 非递归方法-用栈-书上答案-很简洁
// 时间复杂度O(n),空间复杂度O(n)。
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> nums;
        stack<TreeNode *> stk;

        if(root != nullptr) stk.push(root);
        while(!stk.empty()) {
            root = stk.top();
            stk.pop();
            nums.push_back(root->val);

            if(root->right != nullptr) stk.push(root->right);
            if(root->left != nullptr) stk.push(root->left);
        }

        return nums;
    }
};