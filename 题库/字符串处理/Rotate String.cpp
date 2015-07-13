


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
// 时间复杂度O(?),空间复杂度O(n)
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

// 代码2 - 三步反转法
// 时间复杂度O(n),空间复杂度O(1)
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
        if (len == 0 || offset == 0) return A;
        
        offset %= len;
        offset = len - offset;

        // 翻转前半部分
        for (int i = 0; i < offset/2; ++i) {
            char temp = A[i];
            A[i] = A[offset-i-1];
            A[offset-i-1] = temp;
        }
        
        // 翻转后半部分
        for (int i = 0; i < (len-offset)/2; ++i) {
            char temp = A[offset + i];
            A[offset + i] = A[len-i-1];
            A[len-i-1] = temp;
        }
        
        // 翻转全部
        for (int i = 0; i < len/2; ++i) {
            char temp = A[i];
            A[i] = A[len-i-1];
            A[len-i-1] = temp;
        }
        
        return A;
    }
};

// 代码2 - 三步反转法 - 使用STL自带翻转函数
// 时间复杂度O(n),空间复杂度O(1)
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
        if (len == 0 || offset == 0) return A;
        
        offset %= len;
        offset = len - offset;

        // 翻转前半部分
        reverse(A.begin(),A.begin() + offset);
        
        // 翻转后半部分
        reverse(A.begin() + offset,A.end());
        
        // 翻转全部
        reverse(A.begin(),A.end());
        
        return A;
    }
};


/*
三步反转法-说明文章
https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.01.md

举一反三

1、链表翻转。给出一个链表和一个数k，比如，链表为1→2→3→4→5→6，k=2，则翻转后2→1→6→5→4→3，若k=3，
翻转后3→2→1→6→5→4，若k=4，翻转后4→3→2→1→6→5，用程序实现。

2、编写程序，在原字符串中把字符串尾部的m个字符移动到字符串的头部，要求：长度为n的字符串操作时间复杂度为O(n)，空间复杂度为O(1)。 
例如，原字符串为”Ilovebaofeng”，m=7，输出结果为：”baofengIlove”。

3、单词翻转。输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变，句子中单词以空格符隔开。
为简单起见，标点符号和普通字母一样处理。例如，输入“I am a student.”，则输出“student. a am I”。
*/