


// __________________________ Subtree __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/subtree/m/

二叉树中的最大路径和
*/  


/*
You have two every large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. 
Create an algorithm to decide if T2 is a subtree of T1.

Example
T2 is a subtree of T1 in the following case:

       1                3
      / \              / 
T1 = 2   3      T2 =  4
        /
       4
T2 isn't a subtree of T1 in the following case:

       1               3
      / \               \
T1 = 2   3       T2 =    4
        /
       4
Note
A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. 
That is, if you cut off the tree at node n, the two trees would be identical.
*/

// __________________________ Tags __________________________
/*
	 Recursion, Binary Tree,
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
// 代码1 - 用栈
// 为了完全确定找到的子树与T2一致，应该再用后序遍历再来对比一次，才对的，以后加吧，来个后序遍历转字符串的。
// 
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        string t1S = tree2String(T1);
        string t2S = tree2String(T2);
        
        string::size_type position;
        position = t1S.find(t2S);
        if (position == string::npos) {     // 如果没有找到，说明不是 子树。
            return false;
        } else {
            return true;
        }
        
    }
    
    // 前序遍历变成字符串。
    // 把树变成一串字符串。-使用前序遍历来记录。
    string tree2String(TreeNode *root) {
        //queue<TreeNode*> t1Q;
        stack<TreeNode*> t1Q;
        string t1S;
        
        t1Q.push(root);    
        while(!t1Q.empty()) {
            TreeNode *nowNode = t1Q.top();
            t1Q.pop();

            if(nowNode == nullptr) {
                t1S.push_back('#');
                continue;
            }
            
            t1S.push_back(nowNode->val + '0');
            t1Q.push(nowNode->right);
            t1Q.push(nowNode->left);
        }
        
        return t1S;
    }
};