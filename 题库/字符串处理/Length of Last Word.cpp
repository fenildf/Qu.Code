


// __________________________ Length of Last Word  __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/length-of-last-word/
https://leetcode.com/problems/length-of-last-word/

*/  


/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

*/

// __________________________ Tags __________________________
/*
	 String
*/

// __________________________ Extreme Input __________________________
/*
    Input:"c "      Output:1
    Input:" "       Output:0
*/

// __________________________ 实现细节 __________________________ 
// 代码1 - 从倒数的空格开始找起。效率应该是比较高的。
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int length = s.length();
        int word_length = 0;
        for (int i = length - 1; i > -1; --i) {
            if (s[i] == ' ' && word_length != 0) break; // Input:"c "
            if (s[i] != ' ') ++word_length;             // Input:" "
        }
        return word_length;
    }
};

// 代码2 - 顺序扫描每个单词的长度
class Solution {
public:
    int lengthOfLastWord(string& s) {
        // Write your code here
        int length = s.length();
        vector<int> word_s(1,0);    // 针对 Input:""
        int word_length = 0;
        for (int i = 0; i < length; ++i) {
            if (s[i] != ' ') ++word_length;
            if ((i == length -1 || s[i] == ' ' )&& word_length != 0) {
                word_s.push_back(word_length);
                word_length = 0;
            }
        }
        return word_s.back();
    }
};


// 代码3 - 使用STL
class Solution {
public:
    int lengthOfLastWord(string& str) {
        auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
        auto last = find_if_not(first, str.rend(), ::isalpha);
        return distance(first, last);
    }
};