


// __________________________ Product of Array Exclude Itself __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/product-of-array-exclude-itself/

合并排序数组
*/  


/*
Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B WITHOUT divide operation.

Have you met this question in a real interview? Yes
Example
For A = [1, 2, 3], return [6, 3, 2].

*/

// __________________________ Tags __________________________
/*
	Array,
*/

// __________________________ 实现细节 __________________________ 

// 代码1 -使用STL
// 时间复杂度
// 关于原理，可以参考下面文章：《不用除法计算值》
// http://blog.csdn.net/passion_wlz/article/details/8482334
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> front(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            front[i] = nums[i-1] * front[i-1];
        }
        
        vector<long long> back(nums.size(), 1);
        for (int j = nums.size()-2; j > -1; --j) {
            back[j] = nums[j+1] * back[j+1];
        }
        
        for (int k = 0; k < nums.size(); ++k) {
            front[k] = back[k] * front[k];
        }
        
        return front;
    }
};







