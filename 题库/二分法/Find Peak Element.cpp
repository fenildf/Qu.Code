


// __________________________ Find Peak Element   __________________________
/*
题目来源:

http://www.lintcode.com/zh-cn/problem/find-peak-element/

寻找峰值
*/  


/*
There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peek if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.


Example
Given [1, 2, 1, 3, 4, 5, 7, 6]

Return index 1 (which is number 2) or 6 (which is number 7)

Note
The array may contains multiple peeks, find any of them.

Challenge
Time complexity O(logN)
*/

// __________________________ Tags __________________________
/*
	 Binary Search
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用二分法
// 时间复杂度O(log(n)),空间复杂度O(1)
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> num) {
        // write your code here
        int max = num.size();
        int i = max/2;
        int left = 0;
        int right = max-1;
        while(1) {
            if(num[i] > num[i+1] && num[i] > num[i-1]) break;   // find "/\" 曲线
            if (num[i] < num[i+1] && num[i] > num[i-1]) {       // "/" 曲线
                left = i;
            } else if (num[i] < num[i-1]) {       // "\" or "\/" 曲线
                right = i;
            }
            
            i = (left + right)/2;
        }
        
        return i;
    }
};


// __________________________ Find Peak Element   __________________________
/*
题目来源:

https://leetcode.com/problems/find-peak-element/

寻找峰值
*/  


/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/

class Solution {
public:
    int findPeakElement(vector<int>& num) {
        int max = num.size();
        
        // 特殊情况
        if(max == 1) return 0;
        if(max == 2) {
            return num[0] > num[1] ? 0 : 1;
        }
        
        // 这个函数还差 input: [1,2,3]  特殊情况的判断。

        int i = max/2;
        int left = 0;
        int right = max-1;
        while(1) {
            if(num[i] > num[i+1] && num[i] > num[i-1]) break;   // find "/\" 曲线
            if (num[i] < num[i+1] && num[i] > num[i-1]) {       // "/" 曲线
                left = i;
            } else if (num[i] < num[i-1]) {       // "\" or "\/" 曲线
                right = i;
            }
            
            i = (left + right)/2;
        }
        
        return i;
    }
};