


// __________________________ Fast Power   __________________________
/*
题目来源:
http://www.lintcode.com/submission/1459536/

*/  


/*
Calculate the an % b where a, b and n are all 32bit integers.

Example
For 231 % 3 = 2

For 1001000 % 1000 = 0

Challenge 
O(logn)
*/

// __________________________ Tags __________________________
/*
	 Math
*/


// __________________________ 所用到的数据结构 __________________________



// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(log(n)),空间复杂度O(1)
class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(long a, long b, long n) {
        // write your code here
        int s = 1;
        if(n == 0) {
            a = 1;
            s = a%b;
        }
        
        while(n > 0){
            if(n&1) {
                s = s*a%b;
            };
            a = a*a%b;
            n >>= 1;
        }
        return s;
    }  
};


