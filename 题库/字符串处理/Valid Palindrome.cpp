


// __________________________ Valid Palindrome __________________________
/*
题目来源:
https://leetcode.com/problems/valid-palindrome/
http://www.lintcode.com/zh-cn/problem/valid-palindrome/

*/  


/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


*/

// __________________________ Tags __________________________
/*
	 String
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 
// 时间复杂度O(n/2),空间复杂度O(1)
class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        for(int i = 0, j = s.size() - 1; i < j;) {
            if (!isNumOrLetter(s[i])) {
                ++i;
                continue;
            }
            
            if (!isNumOrLetter(s[j])) {
                --j;
                continue;
            }
            
            // 57 为'9'
            if (s[i] == s[j] ||     
            ((s[j] > 57) && (s[i] > 57) && (abs(s[i]-s[j]) == 32)) ) {
                ++i;
                --j;
            } else {
                return false;
            }
            
            
        }
        
        return true;
    }
    
    
    bool isNumOrLetter(char & a) {
        // 分别是 数字,大写字母，小写字母。
        if ((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122)) return true;
        
        return false;
    }
};

