


// __________________________ Search a 2D Matrix  __________________________
/*
题目来源:
https://leetcode.com/problems/search-a-2d-matrix/
http://www.lintcode.com/zh-cn/problem/search-a-2d-matrix/

*/  


/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

// __________________________ Tags __________________________
/*
	 Binary Search
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 还可以再加上二分搜索法 来进行搜索的。
// 时间复杂度O(),空间复杂度O(1)
class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        if (matrix.empty()) return false;
        
        int rowMax = matrix.size()-1;       // 行
        int columnMax = matrix[0].size()-1; // 列
        int rowMin = 0;
        int columnMin = 0;
        
        // 从右上角开始找起,每进行一次判断后，都会削掉一行或者一列。
        while(rowMin <= rowMax && columnMin <= columnMax) {
            if (target > matrix[rowMin][columnMax]) {
                ++rowMin;
                continue;
            } else if (target < matrix[rowMin][columnMax]) {
                --columnMax;
                continue;
            } else if (target == matrix[rowMin][columnMax]) {
                return true;
            }
        }
        
        return false;
    }
};


