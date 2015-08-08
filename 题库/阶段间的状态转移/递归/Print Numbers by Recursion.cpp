


// __________________________ Print Numbers by Recursion  __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/print-numbers-by-recursion/

*/  


/*
Print numbers from 1 to the largest number with N digits by recursion.

Example
Given N = 1, return [1,2,3,4,5,6,7,8,9].

Given N = 2, return [1,2,3,4,5,6,7,8,9,10,11,12,...,99].

Note
It's pretty easy to do recursion like:

recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
however this cost a lot of recursion memory as the recursion depth maybe very large. Can you do it in another way to recursive with at most N depth?

Challenge
Do it in recursion, not for-loop.
*/

// __________________________ Tags __________________________
/*
	 递归;
*/

// __________________________ 实现细节 __________________________ 
// 代码1 - 递归解决
// 时间复杂度O(n),空间复杂度O(n) 
class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
     
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> sonSum; 
        if (n == 1) {
            sonSum = {1,2,3,4,5,6,7,8,9};
        } else if (n > 1) {
           vector<int> temp = numbersByRecursion(n-1);
           sonSum = temp;
           for (int i = 1; i < 10; ++i) {
               int heighDigit = pow(10, n-1)*i;
               sonSum.push_back(heighDigit);
               for(auto x:temp) {
                   sonSum.push_back(x + heighDigit);
               }
           }
        }
       
       return sonSum;
    } 
};