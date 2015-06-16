


// __________________________62- Unique Paths __________________________
/*
题目来源:

https://leetcode.com/problems/unique-paths/
http://www.lintcode.com/en/problem/unique-paths/
*/  


/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there? 【m and n will be at most 100.】

Example

有个表格的，自己看 网址吧

*/

// __________________________ Tags __________________________
/*
	动态规划 , Array
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度
// 直接用递归，运行时间好像会很大，因为重复计算了很多东西。但是代码行数少，才2行
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m == 1 || n == 1) return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};
// 超时

// 代码2 - 递归版
// 用 空间 换 时间
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    long block[101][101];           // 为啥必须是 101，写100就 输出错误答案，底下都已经减1了啊。
    long uniquePaths(int m, int n) {
        // wirte your code here
        if (m == 1 || n == 1) return 1;

        if ( block[m-1][n-1] == 0) block[m-1][n-1] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        return block[m-1][n-1];
    }
};

// 代码3 - 循环版本
/* 为了提高运行速度：
    01-用 空间 换 时间，
    02-用 for 循环代替 使用递归造成的 进程入栈，出栈。
    03-加了辅助行与辅助列，在表格的最左边和最上边。【这样可以减少一个 if 判断】

最后在官网上 运行时间为 0ms.   C++代码，做到了与 C代码运行的一样快欧。
https://leetcode.com/submissions/detail/30273992/
*/
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    long uniquePaths(int m, int n) {
        // wirte your code here
        long block[101][101];       // 用空间换时间
        memset(block,0,sizeof(block));
        
        block[0][1] = 1;   // 加上辅助行与列
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                 block[i+1][j+1] = block[i+1][j] + block[i][j+1];
            }
        }
        return block[m][n]; 
    }
};

// __________________________63 - Unique Paths II  __________________________
// 题目来源: http://www.lintcode.com/en/problem/unique-paths-ii/

/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

// __________________________ Tags __________________________
/*
    动态规划【dynamic programming】, Array
*/



// __________________________ 实现细节 __________________________ 

// 代码1 - for 循环版本
// 有了  Unique Paths 1 的经验后，这里直接上 最快版本。   
class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // 容错处理
        if (obstacleGrid[0][0] == 1) return 0; 
        
        long block[101][101];       // 用空间换时间
        memset(block,0,sizeof(block));
        
        block[0][1] = 1;   // 加上辅助行与列
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    block[i+1][j+1] = 0;
                } else {
                    block[i+1][j+1] = block[i+1][j] + block[i][j+1];
                }
            }
        }
        return block[m][n];
    }
};