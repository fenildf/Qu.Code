


// __________________________ First Bad Version   __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/first-bad-version/sum/

第一个错误的代码版本
*/  


/*
The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is the first bad one. The details interface can be found in the code's annotation part.

Example
Given n = 5:

isBadVersion(3) -> false
isBadVersion(5) -> true
isBadVersion(4) -> true
Here we are 100% sure that the 4th version is the first bad version.

Note
Please read the annotation in code area to get the correct way to call isBadVersion in different language. For example, Java is VersionControl.isBadVersion(v)

Challenge
You should call isBadVersion as few as possible.
*/

// __________________________ Tags __________________________
/*
	 Binary Search
*/

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/

// __________________________ 实现细节 __________________________ 
// 代码1 - 二叉搜索法
// 时间复杂度O(log(n))
// 空间复杂度O(n)     

class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int left = 1;
        int right = n;
        int i = (left + right)/2;
        while (left < right) {
            if (VersionControl::isBadVersion(i)) {  //往左走
                right = i;
            } else {    //往右走
                left = i + 1;
            }
            
            i = (left + right)/2;
        }
        
        return i;
    }
};