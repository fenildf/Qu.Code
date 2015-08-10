


// __________________________ Longest Increasing Continuous subsequence __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/longest-increasing-continuous-subsequence/

最长上升连续子序列
*/  


/*
Give you an integer array (index from 0 to n-1, where n is the size of this array)，find the longest increasing continuous subsequence in this array. (The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)

Have you met this question in a real interview? Yes
Example
For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.

For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.

Note
O(n) time and O(1) extra space.

*/

// __________________________ Tags __________________________
/*
	Array,
*/

// __________________________ 实现细节 __________________________ 

// 代码1 -使用STL
// 时间复杂度O(n) ,空间负责度O(1)
class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& nums) {
        // Write your code here
        if (nums.size() < 3) return nums.size();
        
        // 开始判断方向
        bool isUp = nums[1] > nums[0] ? true : false;     // 2种状态：true，false
        
        int maxLICS = 2;    // 从第3个元素开始判断
        int nowLICS = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if ((isUp && nums[i] > nums[i-1]) || (!isUp && nums[i] < nums[i-1])) {
                ++nowLICS;
            } else {
                maxLICS = max(maxLICS, nowLICS);
                nowLICS = 2;
                isUp = !isUp;
            }
        }
        
        return max(maxLICS, nowLICS);
    }
};







