


// __________________________ Binary Tree Maximum Path Sum  __________________________
/*
题目来源:
https://leetcode.com/problems/binary-tree-maximum-path-sum/
http://www.lintcode.com/zh-cn/problem/binary-tree-maximum-path-sum/

二叉树中的最大路径和
*/  


/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
     
Return 6
*/

// __________________________ Tags __________________________
/*
	 递归
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
// 
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // write your code here
        vector<int> res = maxSonSum(root);
        return max(res[0], res[1]);
    }
    
    /*  vector<int>：第1个为 父结点为一个端点【开始/结束】;
        第2个为  父结点不是其中一个端点;
        第3个为  此结点是否为空那节点。;
    */  
    vector<int> maxSonSum(TreeNode *root) {
        // write your code here
        vector<int> res(3,0);
        if (root == nullptr) return res;
        res[2] = 1;
        
        vector<int> leftSum     =   maxSonSum(root->left);
        vector<int> rightSum    =   maxSonSum(root->right);
        
        
        int left = leftSum[0];
        int right = rightSum[0];
        
        // 计算为其中以端点的情况下。
        // 左右子节点 + 父节点/父节点，看谁的值最大。
        int rootIsEnd   = max(max(left,right) + root->val, root->val);
        
        
        // 计算为非端点的情况。
        vector<int> pool;
        pool.push_back(left + right + root->val);
        pool.push_back(root->val);
        if(leftSum[2] == 1) {
            pool.push_back(left);
            pool.push_back(leftSum[1]);
        }
        if(rightSum[2] == 1) {
            pool.push_back(right);
            pool.push_back(rightSum[1]);
        }
        sort(pool.begin(), pool.end());
        int rootNotEnd = pool[pool.size()-1];
        
        res[0] = rootIsEnd;
        res[1] = rootNotEnd;
        
        return res;
    }
};