


// __________________________ Unique Binary Search Trees __________________________
/*
题目来源:
https://leetcode.com/problems/unique-binary-search-trees/
http://www.lintcode.com/zh-cn/problem/unique-binary-search-trees/

列出所有不同的二叉查找树
*/  


/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

// __________________________ Tags __________________________
/*
	 Tree ，卡特兰数，递归
*/

// __________________________ 实现细节 __________________________ 
// 代码1-使用卡特兰数-直接计算
// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    int numTrees(int n) {
        int f[20] = {0};
        f[0] = 1;
        f[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                f[i] += f[j] * f[i-j-1];
            }
        }
        
        return f[n]; 
    }
};


// 代码2-使用递归？
