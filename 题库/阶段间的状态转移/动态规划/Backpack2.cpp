


// __________________________ Backpack II  __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/backpack-ii/

0/1背包 问题
*/  


/*
Given n items with size Ai and value Vi, and a backpack with size m. What's the maximum value can you put into the backpack?


Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.

Note
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.

Challenge
O(n x m) memory is acceptable, can you do it in O(m) memory?

*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用循环 - 
// 时间复杂度O(n*m),空间复杂度O(m)。
// 使用1维数组，而不再使用二维数组来记录已经运算过的状态。
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> volume, vector<int> value) {
        // write your code here
        vector<int> sum(m + 1, 0);
        
        for (int i = 0; i < volume.size(); ++i) {
            for (int j = m; j >= volume[i]; --j) {
                if ( sum[j] < sum[j-volume[i]] + value[i]) {
                    sum[j] = sum[j-volume[i]] + value[i];
                }
            }
        }
        
        return sum[m];
    }
};


