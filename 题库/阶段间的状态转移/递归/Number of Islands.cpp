


// __________________________ Number of Islands  __________________________
/*
题目来源:
https://leetcode.com/problems/number-of-islands/
http://www.lintcode.com/submission/1105513/

*/  


/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.


*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 
// 代码1 - 递归解决
// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
     enum {
        NOLOOK      = 0,
        HAVELOOK    = 1,
    }; 
     
    int numIslands(vector<vector<char>>& grid) {
        // Write your code here
        vector<vector<bool>> isLook;
        for (int i = 0; i < grid.size(); ++i) {
            vector<bool> temp(grid[0].size(), NOLOOK);
            isLook.push_back(temp);
        }
        
        int landsSumNums = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (isAnLand(grid, isLook, i, j)) {
                    ++landsSumNums;
                }
            }
        }
        
        return landsSumNums;
    }
    
    bool isAnLand(vector<vector<char>>& grid, vector<vector<bool>>& isLook, int i, int j) {
        if (isLook[i][j] == HAVELOOK) return false;
        
        isLook[i][j] = HAVELOOK;
        if (grid[i][j] == '0') {
            return false;
        } else {
            if (i != 0) isAnLand(grid, isLook, i - 1, j);   
            
            if (i != grid.size() - 1) isAnLand(grid, isLook, i + 1, j);
            
            if (j != 0) isAnLand(grid, isLook, i, j - 1);
            
            if (j != grid[0].size() - 1) isAnLand(grid, isLook, i, j + 1);
            
            return true;
        }
    }
};