


// __________________________ Search Range in Binary Search Tree __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/search-range-in-binary-search-tree/

二叉查找树中搜索区间
*/  


/*
Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. 
Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. 
Return all the keys in ascending order.

Example
If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].

    20
   /  \
  8   22
 / \
4   12
*/

// __________________________ Tags __________________________
/*
	 BST,lintCode 自己出的题目。
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
// 
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> list;
    bool first;
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        searchNode(root, k1, k2);   
        sort(list.begin(), list.end());

        return list;
    }
    
    vector<int> searchNode(TreeNode* root, int k1, int k2) {
        // write your code here
        if (root == nullptr) return list;
        int mid = root->val;
        
        if (mid >= k1 && mid <= k2) list.push_back(mid);

        if (mid < k2) searchNode(root->right, k1, k2);
        if (mid > k1) searchNode(root->left, k1, k2);    
        
        return list;
    }
};