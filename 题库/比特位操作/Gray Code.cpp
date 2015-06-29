


// __________________________ O(1) Check Power of 2  __________________________
/*
题目来源:
https://leetcode.com/problems/gray-code/
http://www.lintcode.com/zh-cn/problem/gray-code/#

*/  


/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

// __________________________ Tags __________________________
/*
	 Backtracking - 回溯法？
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(2^n),空间复杂度O(1)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code;
        code.push_back(0);
        
        if (n == 0) {
            return code;
        }
        
        code.push_back(1);
        
        for(int i = 1; i < n; ++i) {
           int high_bit = 1<<i;
           for (int j = code.size()-1; j >= 0; --j) {
               code.push_back(high_bit|code[j]);
           }
        }
        
        return code;
    }
};



/*  思路：
01-先把第1位 写入 0，然后写1 压入到数组中去。
02-把第2位置为1 = high_bit，然后把数组中的元素倒序取出来，与  high_bit 相与。
03-把第2步产生的新元素都压入到数组中去。

     0 0 0
     0 0 1
     0 1 1
     0 1 0
     ------ // 第1，2位正好上下镜像，并且满足要求：  两个连续的数值仅有一个二进制的差异。     
     1 1 0
     1 1 1
     1 0 1
     1 0 0
*/