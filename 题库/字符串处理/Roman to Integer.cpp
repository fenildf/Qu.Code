


// __________________________ Roman to Integer  __________________________
/*
题目来源:
https://leetcode.com/problems/roman-to-integer/
http://www.lintcode.com/zh-cn/problem/roman-to-integer/

*/  


/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.


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
     * @param s Roman representation
     * @return an integer
     */
    
    /*
    右加左减：
在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
但是，左减时不可跨越一个位数。比如，99不可以用IC（100 - 1）表示，而是用XCIX（[100 - 10] + [10 - 1]）表示。（等同于阿拉伯数字每位数字分别表示。）
左减数字必须为一位，比如8写成VIII，而非IIX。
右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
    */ 
     
    char digchar[7] = {'I',    'V',    'X',    'L',    'C',    'D',    'M', }; 
    const int  digNum[7] = {1,     5,      10,     50,     100,    500,    1000 };
    const int  subNum[3] = {1, 10, 100};     // 左减的数字有限制，仅限于I、X、C
    
    int romanToInt(string &s) {
        // Write your code here
        
        int mid = 0;
        vector<int> pool;
        
        // 字符串转化成数字
        for (int i = 0; i < s.size(); ++i) {
            pool.push_back(char2int(s[i]));
        }
        
        int sum = 0;
        // 在池子里面，从左往右遍历，先看是不是一个 左减数，其次判断右边的数字是否比它大。
        for (int i = 0; i < pool.size(); ++i) {
            if (isSubNum(pool[i]) && i+1 < pool.size()) {
                if (pool[i] < pool[i+1]) {
                    sum -= pool[i];
                    ++i;
                } 
            } 
            
            // 如果有左减数，就是加上了右边那位，没有左减数，就是加上了那一位。
            sum += pool[i];
        }
        
        return sum;
    }
    
    int char2int(char er) {
        int i = 0;
        for (i = 0; i < 7 ; ++i) {
            if (digchar[i] == er) break;
        }
        
        return digNum[i]; 
    }
    
    
    bool isSubNum(int num) {    // 检测是否是左减数。
        for (int i = 0; i < 3; ++i) {
            if (num == subNum[i]) return true;
        }
        
        return false;
    }
};
