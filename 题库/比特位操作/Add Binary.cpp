


// __________________________ Add Binary __________________________
/*
题目来源:

https://leetcode.com/problems/add-binary/
http://www.lintcode.com/zh-cn/problem/add-binary/

*/  


/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

// __________________________ Tags __________________________
/*
	 Math,String
*/

// __________________________ 实现细节 __________________________ 

// 代码1 -- 数字 和字符串 转化这块写的用点SB了。代码2有改进
// 时间复杂度O(m~n),空间复杂度O(n + m)
/*
    其实这个已经就是 大数【2进制位数超过 64 ～128位的 数字...】 的加法了, 用相同方法可以 实现大数的 减法。
    但是 大数 的除法 和 乘法 就不知道 该如何实现了...  
*/ 
   

class Solution {
public:
    string addBinary(string& a, string& b) {
        string s_big;
        string s_small;
        
        if (a.size() >= b.size()) {
            s_big = a;
            s_small = b;
        } else {
            s_big = b;
            s_small = a;
        }
        
        // 计算最小长度
        int minl = s_small.size();
        int maxl = s_big.size();
        int num_small   = 0;
        int num_big     = 0;
        
        for (int i = 0; i < maxl; ++i) {
            if (i < minl) {
                char c_s[1];
                c_s[0] = s_small[s_small.size()-1-i];
                num_small   = atoi(c_s);
            }
            
            char c_b[1];
            c_b[0] = s_big[s_big.size()-1-i];
            num_big     += atoi(c_b);
            
            int temp = (num_small + num_big)%2;     //低位
            num_big = (num_small + num_big)/2;      //高位
            num_small = temp;
            
            if (num_small == 0) {
                s_big[s_big.size()-1-i] = '0';
            } else {
                s_big[s_big.size()-1-i] = '1';
            }
            
            num_small = 0;
            
            //  过了s_small 最后一位时,并且进位为0时. 
            if (i >= minl -1 && num_big == 0) break;
        }
        
        // s_big 最前面需要进1位。
        if (num_big == 1) {
            s_big.insert(s_big.begin(),'1');        //在最前插入1
        }
        
        
        return s_big;
    }
};


/*  用到的一些知识：int 和 char 型的转换

这要用到ASCII码的知识，粗略讲一下

字符'0'的ASCII码为48，然后是'1' '2' '3' ... '9'

字符' '(空格)的ASCII码为32.

字符'A'的ASCII码为65，然后是'B' 'C' ... 'Z'

字符'a'的ASCII码为97，然后是'b' 'c' ... 'z'

所以，把一个数字字符ch，转为一个整数，就是ch-'0'当然ch-48也行

因为C和C++中，字符和整型是一样的，可以隐式转换

*/

s_big[s_big.size()-1-i] = num_small + '0';      // int型  转 char型
num_big += s_big[s_big.size()-1-i] - '0';       // char型 转 int型

// 代码2 -- 
// 时间复杂度O(m~n),空间复杂度O(n)
class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string s_big;
        int minl;  // 计录最小长度
        
        if (a.size() >= b.size()) {
            s_big = a;
            minl = b.size();
        } else {
            s_big = b;
            minl = a.size();
        }
        
        int num_high = 0;
        
        for (int i = 0; i < s_big.size(); ++i) {
            const int num_a = (i < a.size()) ? a[a.size()-1-i] - '0' : 0 ;
            const int num_b = (i < b.size()) ? b[b.size()-1-i] - '0' : 0 ;
            
            const int low = (num_a + num_b + num_high)%2;   //低位
            num_high = (num_a + num_b + num_high)/2;        //高位

            s_big[s_big.size()-1-i] = low + '0';
            
            //  过了s_small 最后一位时,并且进位为0时. 
            if (i >= minl -1 && num_high == 0) break;
        }
        
        // s_big 最前面需要进1位。
        if (num_high == 1) {
            s_big.insert(s_big.begin(),'1');        //在最前插入1
        }
        
        return s_big;
    }
};