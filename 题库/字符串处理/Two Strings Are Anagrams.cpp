


// __________________________ Two Strings Are Anagrams __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/two-strings-are-anagrams/

*/  


/*
Write a method anagram(s,t) to decide if two strings are anagrams or not.

Have you met this question in a real interview? Yes
Example
Given s="abcd", t="dcab", return true.

Challenge
O(n) time, O(1) extra space

*/

// __________________________ Tags __________________________
/*
	 String
*/

// __________________________ 解题思路 __________________________ 
/*
    1：考虑到ANSCI字符只有256个，用一个 int 型数组来记录 string s 中各字符出现的次数，再减去 string t 中各字符出现的次数。
    最后如何 出现负数 ，说明 不是颠倒字母顺序构成的。

    2：空间优化：其实只要考虑 26个字母×2 = 54 的，没有必要开 256 数组的。但是加上数组转化，运行时间上会拉长。
*/

// __________________________ 实现细节 __________________________ 
// 代码1 
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        int len1 = s.length();
        int len2 = t.length();
        if (len1 != len2) return false;
        
        int same[256];
        memset(same,0,sizeof(same));
        
        for (int i = 0; i < len1; ++i) {
            ++same[s[i]];
            --same[t[i]];
        }
        
        for (int j = 0; j < 256; ++j) {
            if (same[j] < 0) return false;
        }
        
        return true;
    }
};

