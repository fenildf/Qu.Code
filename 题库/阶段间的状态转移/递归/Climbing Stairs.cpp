


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

// __________________________ 解决思路 __________________________
/*
思路1：只要能联系到 斐波拉契数列的话，就容易了。
    可以这样想，跳到 第n级台阶的前一步，要么在 n-1 ,要么在 n-2 级台阶。依次类推到1级台阶。
    所以 f(n) = f(n-1) + f(n-2) 【可以用归纳法证明这个公式】

*/ 


// __________________________ 类似题目 __________________________ 
/*
【题 目1】一个台阶一共有n阶，一次起跳可以跳一阶，也可以跳二阶。问总共有多少中跳法，并对时间复杂度进行分析。

【题 目2】我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
    请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

// 这两道题目 是一样的。    
*/

// __________________________ 跳台阶 __________________________
/*
【题 目2】一个台阶一共有n阶，一次起跳可以跳一阶，也可以跳二阶。也可以一次跳3级，问总共有多少中跳法，并对时间复杂度进行分析。

*/


// __________________________ 解决思路 __________________________
/*
思路1：
    f(n) = f(n-1) + f(n-2) + f(n-3) 
*/ 

