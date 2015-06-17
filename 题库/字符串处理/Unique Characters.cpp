


// __________________________ Unique Characters  __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/unique-characters/

*/  


/*
mplement an algorithm to determine if a string has all unique characters.

Example
Given "abc", return true.

Given "aab", return false.

Challenge
What if you can not use additional data structures?

*/

// __________________________ Tags __________________________
/*
	 String, Array, Cracking The Coding Interview[面试金典那本书]
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here 
        if (str.length() > 256)return false;

        bool same[256];
        memset(same,0,sizeof(same));
        
        for (int i = 0; i < str.length(); ++i) {
            if (same[str[i]] == true) {
                return false;
            }
            same[str[i]] = true;
        }
        return true;
    }
};