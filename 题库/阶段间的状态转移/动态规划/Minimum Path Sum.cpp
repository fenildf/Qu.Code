


// __________________________ Minimum Path Sum  __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/minimum-path-sum/
https://leetcode.com/problems/minimum-path-sum/

最小路径和
*/  


/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用二维数组记录 状态值
// 时间复杂度O(n*m),空间复杂度O(n*m)。
class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int memory[400][400];
        memset(memory,0,sizeof(memory));   // 
        
        if (grid == vector<vector<int>> ()) return 0;   // 空返回 0
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0) {       // 两个边界要特殊化处理。
                    memory[i+1][j+1] = grid[i][j] + memory[i+1][j]; 
                } else if (j == 0) {
                    memory[i+1][j+1] = grid[i][j] + memory[i][j+1]; 
                }
                else {
                   memory[i+1][j+1] = grid[i][j] + min(memory[i+1][j], memory[i][j+1]); 
                }
            }
        }
        
        return memory[grid.size()][grid[0].size()];
    }
};

// 代码2 - 使用一维数组记录 状态值，滚动数组的原理
// 时间复杂度O(n*m),空间复杂度O(m)。
class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        vector<int> memory(grid[0].size() + 1, 0);      // 加一行辅助行
        
        if (grid == vector<vector<int>> ()) return 0;   // 空返回 0
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0) {       // 两个边界要特殊化处理。
                    memory[j+1] = grid[i][j] + memory[j]; 
                } else if (j == 0) {
                    memory[j+1] = grid[i][j] + memory[j+1]; 
                }
                else {
                   memory[j+1] = grid[i][j] + min(memory[j], memory[j+1]); 
                }
            }
        }
        
        return memory[grid[0].size()];
    }
};

