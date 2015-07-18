


// __________________________ Longest Common Subsequence __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/longest-common-subsequence/

最长公共子序列
*/  


/*
Medium Longest Common Subsequence

36% Accepted
Given two strings, find the longest common subsequence (LCS).

Your code should return the length of LCS.


Example
For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.

For "ABCD" and "EACB", the LCS is "AC", return 2.

Clarification
What's the definition of Longest Common Subsequence?

https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
http://baike.baidu.com/view/2020307.htm

*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用循环 - 
// 时间复杂度O(n*m),空间复杂度O(m*n)。
// 使用2维数组来记录已经运算过的状态。
class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int memory[100][100];
        memset(memory,0,sizeof(memory));
        
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if(A[i] == B[j]) {
                    memory[i+1][j+1] =  memory[i][j] + 1;
                } else {
                    memory[i+1][j+1] = max(memory[i+1][j], memory[i][j+1]);
                }
            }
        }
        
        return memory[A.size()][B.size()];
    }
};


