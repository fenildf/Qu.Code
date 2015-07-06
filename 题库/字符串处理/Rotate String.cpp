


// __________________________ Rotate String __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/rotate-string/

*/  


/*
Given a string and an offset, rotate string by offset. (rotate from left to right)


Example
Given "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
Challenge
Rotate in-place with O(1) extra memory.

*/

// __________________________ Tags __________________________
/*
	 String
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用STL，用了一个辅助 string
// 时间复杂度O(1),空间复杂度O(n)
class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        int len = A.size();
        if (len == 0) return A;
        
        offset %= len;

        A.append(A);
        string C(A,len - offset, len);
        return C;
    }
};

