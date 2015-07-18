


// __________________________ Longest Common Substring __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/longest-common-substring/

最长公共子串
*/  


/*
Given two strings, find the longest common substring.

Return the length of it.


Example
Given A = "ABCD", B = "CBCE", return 2.

Note
The characters in substring should occur continuously in original string. This is different with subsequence.

Challenge
O(n x m) time and memory.

*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用暴力法 
// 时间复杂度O(n*m),空间复杂度O(1)。
/*  时间优化：
1： i < A.size()-maxLength; 当后面要查的字符串长度小于已经找到的子串的长度时，没必要遍历下去。
2： j = max(j, j + k - 1);  如果找到一个很长的子串，则 j 可以跳跃过这段子串的长度遍历。
*/ 
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        
        int maxLength = 0;
        
        for (int i = 0; i < A.size()-maxLength; ++i) {      // 小于已经找到的长度时，没必要找
            
            for (int j = 0; j < B.size()-maxLength; ++j) {
                
                // i 和 j 确定已经找到的长度
                int sonLen = 0;
                for (int k = 0; k+i < A.size() && k+j < B.size(); ++k) {
                    if(A[i+k] == B[j+k]) {
                        ++sonLen;
                    } else {
                       j = max(j, j + k - 1);     
                       break;
                    }
                }
                maxLength = max(maxLength, sonLen);
                sonLen = 0;
            }
        }
        
        return maxLength;
    }
};


