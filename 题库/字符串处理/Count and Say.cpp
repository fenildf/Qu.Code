


// __________________________ Count and Say __________________________
/*
题目来源:
https://leetcode.com/problems/count-and-say/
http://www.lintcode.com/zh-cn/problem/count-and-say/

*/  


/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*/

// __________________________ Tags __________________________
/*
	 String
*/

// __________________________ 实现细节 __________________________ 

// 代码1 
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        string num = "1";
        string mid = "";
        
        for (int i = 1; i < n; ++i) {
            int goal = num[0] - '0';
            int sum = 0;
            for (int j = 0; j < num.size(); ++j) {
                if (num[j] - '0' == goal) {     // 字符 转 int
                    ++sum;
                } else {
                    mid.push_back(sum + '0');        // int 转 字符
                    mid.push_back(goal + '0');
                    sum = 1;
                    goal = num[j] - '0';
                }
                
                // 运行到最后一个元素了。
                if (j == num.size() - 1) {
                    mid.push_back(sum + '0');
                    mid.push_back(goal + '0');  
                }
            }
            num = mid;
            mid = "";
        }
        
        return num;
    }
};

