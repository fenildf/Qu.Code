


// __________________________ Fibonacci  __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/fibonacci/

*/  


/*
Find the Nth number in Fibonacci sequence.

A Fibonacci sequence is defined as follow:

The first two numbers are 0 and 1.
The i th number is the sum of i-1 th number and i-2 th number.
The first ten numbers in Fibonacci sequence is:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

Example
Given 1, return 0

Given 2, return 1

Given 10, return 34

Note
The Nth fibonacci number won't exceed the max value of signed 32-bit integer in the test cases.
第N斐波纳契数不会超过符号的32位整数中的测试用例的最大值。
*/

// __________________________ Tags __________________________
/*
	 Non Recursion-非递归;    Enumeration-枚举法;    Mathematics-数学归纳法？;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 用递归，直接超时
// 时间复杂度O(?),空间复杂度O(n)

class Solution{
public:
    int fibonacci(int n) {
        // write your code here
        if (n == 1) return 0;
        if (n == 2) return 1;
        
        return fibonacci(n-1) + fibonacci(n-2);
    }
};

// 代码2 - 用枚举
// 时间复杂度O(n),空间复杂度O(n)
// 这里还可以改进一下，使用STL中的动态数组。
class Solution{
public:
    int fibonacci(int n) {
        int num[100]; 
        memset(num,0,sizeof(num));
        
        num[2] = 1;
        for (int i = 3; i < n + 1; ++i)  num[i] = num[i-1] + num[i-2];
           
        return num[n];
    }
};

// 代码3 - 使用STL的动态数组
// 时间复杂度O(n),空间复杂度O(n)
class Solution{
public:
    int fibonacci(int n) {

        vector<int> num(n, 0);
        num[2] = 1;
        for (int i = 3; i < n + 1; ++i)  num[i] = num[i-1] + num[i-2];
           
        return num[n];
    }
};


// 代码4 
/*
    考虑到 菲波拉契 数列增长的特殊性，当返回值只是最后一项时，
    可以只用 三个临时变量 来存储就够了，而不需要一个动态数组。
*/
// 时间复杂度O(n),空间复杂度O(3)【即是O(1)】
class Solution{
public:
    int fibonacci(int n) {

        int num[3] = {0,1,0};

        for (int i = 3; i < n + 1; ++i) {
            num[2] = num[0] + num[1];
            num[0] = num[1];
            num[1] = num[2];
        }  
         
        if (n == 1) return num[0];
        if (n == 2) return num[1];   
        return num[2];
    }
};


