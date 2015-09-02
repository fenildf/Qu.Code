


// __________________________ Digit Counts   __________________________
/*
题目来源:

http://www.lintcode.com/en/problem/digit-counts/
统计数字
*/  


/*
Count the number of k's between 0 and n. k can be 0 - 9.

Have you met this question in a real interview? Yes
Example
if n=12, k=1 in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], we have FIVE 1's (1, 10, 11, 12)
*/

// __________________________ Tags __________________________
/*
	 Enumeration
*/

// __________________________ 实现细节 __________________________ 
class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int sum = 0;
        for (int i = 0; i < n+1; ++i) {
            sum += decomposeDigit(i, k);
        }
        return sum;
    }
    
    int decomposeDigit(int n, int goal) {
        vector<int> pool;
        
        // 初始池子
        if(n == 0) {
            pool.push_back(0);
        }
        
        while (n != 0) {
            int i = n%10;
            n /= 10;
            pool.push_back(i);
        }
        
        // 统计池子中 goal 出现的个数。
        int sum = 0;
        for(int i = 0; i < pool.size(); ++i) {
            if (pool[i] == goal) ++sum;
        }
        
        return sum;
    }
};
