


// __________________________ Climbing Stairs  __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/climbing-stairs/

*/  


/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Example
Given an example n=3 , 1+1+1=2+1=1+2=3

return 3


*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - for 循环
// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:

    int climbStairs(int n) {
        vector<int> num;
        num.resize(n);
        // 或者是： vector<int> num(n, 0);
        
        num[0] = 1;
        num[1] = 1;
        for (int i = 2; i < n + 1; ++i)  num[i] = num[i-1] + num[i-2];
           
        return num[n];
    }
};

// 代码2 - for 循环
// 时间复杂度O(n),空间复杂度O(1)
class Solution{
public:
    int climbStairs(int n) {

        int num[3] = {1,1,0};

        for (int i = 2; i < n + 1; ++i) {
            num[2] = num[0] + num[1];
            num[0] = num[1];
            num[1] = num[2];
        }  
         
        if (n < 2) return num[n];  
        return num[2];
    }
};







