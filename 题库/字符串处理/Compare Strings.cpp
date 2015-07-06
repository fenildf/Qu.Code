


// __________________________ Compare Strings __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/compare-strings/

*/  


/*
Compare two strings A and B, determine whether A contains all of the characters in B.

The characters in string A and B are all Upper Case letters.


Example
For A = "ABCD", B = "ACD", return true.

For A = "ABCD", B = "AABC", return false.

Note
The characters of B in A are not necessary continuous or ordered.


*/

// __________________________ Tags __________________________
/*
	 String
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 
// 时间复杂度O(n + 26),空间复杂度O(1)
class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if (B.size() > A.size()) return false;
        
        vector<int> letter(26, 0);
        
        for (int i = 0; i < A.size(); ++i) {    // 65 是 大写字母A
            ++letter[A[i]-65];
            if (i < B.size()) --letter[B[i]-65];
        }
        
        for (int i = 0; i < 26; ++i) {
            if (letter[i] < 0) return false;
        }
        
        return true;
    }
};

