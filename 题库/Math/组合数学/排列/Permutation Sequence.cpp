


// __________________________ Permutation Sequence  __________________________
/*
题目来源:
https://leetcode.com/problems/permutation-sequence/
http://www.lintcode.com/zh-cn/problem/permutation-sequence/

第k个排列
*/  


/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

*/

// __________________________ Tags __________________________
/*
	 排列，Math
*/

// __________________________ 实现细节 __________________________ 
// 代码1-从后往前遍历，
// 时间复杂度O(n^2),空间复杂度O(1)

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        vector<int> num_pool;       // 把 num_pool 里面的数一个个的取出来，放入 string 中。
        num_pool.push_back(1);
       
        long a[9];                  // 统计每种 n 下面总共有多少个数。
        a[0] = 1;
        for (int i = 1; i < n; ++i) {
           a[i] = a[i-1] * (i+1);
           num_pool.push_back(i+1);
        }
       
       
        string ret;
        --k;    // 把 边界 0 算进去
        while(n > 0) {
            long pool = a[n-1]/n;       // 平分这个数
            int one = k/pool;           // 第 k 个排列 的第1位为多少。
            int tou = num_pool[one];    // 从num_pool中取出这个数。
            num_pool.erase(num_pool.begin() + one);  // 然后删掉这个取出的数。
            ret.push_back(tou + '0');
            --n;
            k %= pool;
        }
       
        return ret;
    }   
};
