


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

// 代码1 - 用递归，直接超时【树形递归】
// 时间复杂度O(1.618^n),空间复杂度O(n)

class Solution{
public:
    int fibonacci(int n) {
        // write your code here
        if (n == 1) return 0;
        if (n == 2) return 1;
        
        return fibonacci(n-1) + fibonacci(n-2);
    }
};

// 代码2 -【尾递归】- 【需要编译器支持，已知 C++ 支持，python不支持】
// 详细讲解 尾递归的 文章：http://lixinzhang.github.io/fei-bo-na-qi-shu-lie-ji-wei-di-gui.html
// 不会有重复计算的事情发生。这样就保证了时间至少不会超时。
// 空间复杂读： 占用常量栈空间 
class Solution{
public:
    int fibonacci(int n) {

        if (n == 1) return 0;
        if (n == 2) return 1;
        
        return fibonacciThree(0, 1, n-2);
    }
    
    int fibonacciThree(int a1, int a2, int n) {  
        if(n == 1) {
            return a2;  
        } else {
            return fibonacciThree(a2, a1 + a2, n-1);
        }
    }
};

// 代码3 - 用枚举
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

// 代码4 - 使用STL的动态数组
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


// 代码5 迭代实现
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
            num[2] = num[0] + num[1];       // 这个叫 辗转相加法？
            num[0] = num[1];
            num[1] = num[2];
        }  
         
        if (n == 1) return num[0];
        if (n == 2) return num[1];   
        return num[2];
    }
};

// 代码6 - 公式实现 - 基于通项公式的快速算法【黄金分割率法】
// 时间复杂度O(1),空间复杂度O(1)
/*
    Fibonacci数列通项公式推导  http://blog.163.com/zhuxun2@126/blog/static/3631555720071024105814506/
    由于double类型的精度还不够，所以程序算出来的结果会有误差，如果把公式展开计算，得出的结果就是正确的。
    具体有多精确要 以后来跑数据了才知道。
    测试代码：两个函数的结果的差。差值不为0就打印到屏幕上。
*/ 
class Solution{
public:
    int fibonacci(int n) {
        n = n-1;        // n = 1时， return 0.
        double gh5=sqrt((double)5);  
        return (pow((1+gh5),n)-pow((1-gh5),n))/(pow((double)2,n)*gh5);
    }
};

// 代码7 - 用矩阵来求 - 【待自己实现一遍】
// 时间复杂度O(log(n)),空间复杂度O(?)
// 对与求 输入1个数n(1 <= n <= 10^18)。 返回f(n)的题目，并且限时 1000ms 就必须上 矩阵法来求解了。

/*  参考文章
    http://www.zhihu.com/question/22854639
    Fibonacci数计算中的两个思维盲点及其扩展数列的通用高效解法：
    http://www.cnblogs.com/flyinghearts/archive/2012/02/28/2372530.html
    http://www.hawstein.com/posts/8.1.html
    http://www.gocalf.com/blog/calc-fibonacci.html

*/




// __________________________ 黑科技 __________________________ 

// 一些黑科技： 不一定快，但是绝对是少见。
// 黑科技1 汇编语言 开栈！！！！ 【这是用了在线汇编技术啊】

/*
    一、如用递归写法，则可以使用手动增栈命令
    若用C++语言编写该代码且用VC++编译器编译，可用以下pragma命令增栈
    #pragma comment(linker,"/STACK:1024000000,1024000000")
    若用GCC/G++编译，则可使用汇编命令来增栈（此处略）
    http://www.zhihu.com/question/22854639
*/
#include <cstdio>
#include <cstring>
const int MaxN = 1000000;
int fib[MaxN + 1];

int f(int x){
    if (x == 1 || x == 2) return 1;
    if (fib[x] != -1) return fib[x];
    return fib[x] = (f(x - 1) + f(x - 2)) % 10007;
}

int main(){
    for (int i = 1; i <= MaxN; i++) fib[i] = -1;
    static int stack[MaxN * 5], bak;
    asm __volatile__
    (
        "movl %%esp, %0\n\t"
        "movl %1, %%esp\n\t": 
        "=g"(bak):
        "g"(stack + MaxN * 5 - 1):
    );
    printf("%d\n", f(MaxN));
    asm __volatile__
    (
        "movl %0, %%esp\n\t" :
        :
        "g"(bak)
    );
    return 0;
}


// __________________________ 延伸题目 __________________________ 

/*
延伸题目 1
问题是 f1=f2=1 输入n 求fn除以10007的余数 我用一个递归求fn 我确信都没问题 用比较小的数据测试也ok 
但问题是约定n数据小于等于1000000 我拿1000000测试就直接跪 该怎么写呀?

原网址：http://www.zhihu.com/question/22854639
*/

// 代码1 迭代实现-递推
class Solution{
public:
    int fibonacci(int n) {

        int num[3] = {0,1,0};

        for (int i = 3; i < n + 1; ++i) {
            num[2] = num[0] + num[1];       // 这个叫 辗转相加法？
            num[2] = num[2]%10007;          // 为啥写这里，得要好好想一想。
            num[0] = num[1];
            num[1] = num[2];
        }  
         
        if (n == 1) return num[0];
        if (n == 2) return num[1];   
        return num[2];
    }
};


/*
延伸题目 2
计算F(n)最后四位数（某道ACM题）的代码。

原网址：http://www.cppblog.com/flyinghearts/archive/2010/07/16/118593.html
*/


/*
延伸题目 3
求解F[n]对某个素数的余数，比如

Input
输入1个数n(1 <= n <= 10^18)。
Output
输出F(n) % 1000000009的结果。

原题目网址：http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1242
*/


// 把所有的 延伸题 都收集起来了，真心变态啊。
// http://www.cnblogs.com/Knuth/archive/2009/09/04/1559951.html



