


// __________________________ Sqrt(x)  __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/sqrtx/

*/  


/*
Implement int sqrt(int x).

Compute and return the square root of x.

Have you met this question in a real interview? Yes
Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3

Challenge
O(log(x))
*/

// __________________________ Tags __________________________
/*
	 Binary Search
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用STL
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int number) {
        // write your code here

        return sqrtf(number); 
    }
};

// 代码2 - 使用二分法
