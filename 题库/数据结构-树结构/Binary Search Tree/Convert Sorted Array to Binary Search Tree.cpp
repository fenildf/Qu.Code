


// __________________________ IConvert Sorted Array to Binary Search Tree  __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height/#
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

把排序数组转换为高度最小的二叉搜索树
*/  


/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Example
Given [1,2,3,4,5,6,7], return

     4
   /   \
  2     6
 / \    / \
1   3  5   7
Note
There may exist multiple valid solutions, return any of them.
*/

// __________________________ Tags __________________________
/*
	 BST,
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
// 问题：初始数组如果很大的话，会崩掉的吧。把栈空间用尽，以后搞一个迭代版本的。
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int maxSize = nums.size();
        
        if (maxSize == 0) return (TreeNode *)nullptr;
        
        int height = 1;
        int maxNodeSum;
        for (; ; ++height) {
            maxNodeSum = pow(2, height) - 1;
            if (maxNodeSum >= maxSize) break;
        }
        
        int mid = (maxNodeSum-1)/2;
        
        int upNodeSum;      // 记录上面所有层的总节点数量。
        int thisNdoeSum;    // 记录这一层的节点总数量。
        int thisNodeNum;    // 这一层实际节点的总数量，肯定是大于0的。
        if(height > 1) {    // 如果树的高度大于1
           upNodeSum = pow(2, height-1) - 1;
           thisNdoeSum = maxNodeSum - upNodeSum;
           thisNodeNum = maxSize - upNodeSum; 
           mid = (upNodeSum - 1)/2 + min(thisNodeNum, thisNdoeSum/2); 
        }
        
        TreeNode * root = new TreeNode(nums[mid]);
        if(mid == 0) return root;
        
        vector<int> Left(nums.begin(),nums.begin() + mid);
        root->left = sortedArrayToBST(Left);
        if (mid < maxSize -1) {
            vector<int> Right(nums.begin() + mid + 1,nums.end());
            root->right = sortedArrayToBST(Right);
        }
        
        return root;
    }
};
