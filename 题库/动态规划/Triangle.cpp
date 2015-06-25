


// __________________________ Triangle  __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/triangle/
https://leetcode.com/problems/triangle/

*/  


/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 动态规划 - 
// 时间复杂度O(n),空间复杂度O(1)。
// 自顶向下，SB了，状态越来越多【每一个阶段都比上一个阶段多一种状态。】，后面反而需要把最后一行进行对比。
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int numDeep = triangle.size();
        if (numDeep == 1) return triangle[0][0];    // 只有1行
        
        for (int i = 1; i < numDeep; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                int add = 0;
                if (j == 0) {   // 这一行最左边
                    add = triangle[i-1][j];         
                } else if (j == triangle[i].size()-1) {     // 这一行最右边
                    add = triangle[i-1][j-1];       
                } else {
                    add = triangle[i-1][j] < triangle[i-1][j-1] ? triangle[i-1][j] : triangle[i-1][j-1];
                }
                triangle[i][j] += add;
            }
        }
        
        // 在最后一行中寻找最小的数字。
        int minpath = triangle[numDeep-1][0];
        for (int j = 0; j < triangle[numDeep-1].size(); ++j) {
            if (minpath > triangle[numDeep-1][j]) minpath =  triangle[numDeep-1][j]; 
        }
        
        return minpath;
    }
};     


// 代码2 - 动态规划 - 
// 时间复杂度O(n),空间复杂度O(1)。
// 自底向上，这样就大大简化代码了。每一个阶段都比上一个阶段少一种状态。到最后就只有1种状态。
// 缺点，修改了原始数据 triangle。
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int numDeep = triangle.size();
        
        for (int i = numDeep-1; i > 0; --i) {
            for (int j = 0; j < triangle[i-1].size(); ++j) {
                triangle[i-1][j] += min(triangle[i][j+1], triangle[i][j]);
            }
        }
        
        return triangle[0][0];
    }
};




// 代码3 - 借助辅助行，不修改原始数据。
// 时间复杂度O(n),空间复杂度O(m)。 其中m是数字三角形的总行数。