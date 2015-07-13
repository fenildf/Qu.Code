


// __________________________ Reverse Words in a String __________________________
/*
题目来源:
https://leetcode.com/problems/reverse-words-in-a-string/
http://www.lintcode.com/zh-cn/problem/reverse-words-in-a-string/

*/  


/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:

What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

*/

// __________________________ Tags __________________________
/*
	 String
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 用了2个辅助 string
// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    void reverseWords(string &s) {
    string rs;  
        for (int i = s.length()-1; i >= 0; )  
        {  
            while (i >= 0 && s[i] == ' ') i--;  
            if (i < 0) break;  
            if (!rs.empty()) rs.push_back(' ');  
            string t;  
            while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);  
            reverse(t.begin(), t.end());  
            rs.append(t);  
        }  
        s = rs;
    }
};