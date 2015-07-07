


// __________________________ Merge Sorted Array __________________________
/*
题目来源:

https://leetcode.com/problems/merge-sorted-array/
http://www.lintcode.com/en/problem/merge-sorted-array/

合并排序数组
*/  


/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.

*/

// __________________________ Tags __________________________
/*
	Array, Two Pointers
*/

// __________________________ 实现细节 __________________________ 

// 代码1 -使用STL
// 时间复杂度
// 先抹除 nums1 尾部的元素，再插入 nums2，最后排序。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m, nums1.end());
        nums1.insert(nums1.begin()+m, nums2.begin(), nums2.begin()+n);
        sort(nums1.begin(), nums1.end());
    }
};

// 代码2 -对于数组，如何解决。
class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        for (int i = 0; i < n; ++i) {
            A[m+i] = B[i];
        }
        
        sort(A, A + m + n );
    }
};









// __________________________  Merge Sorted Array II __________________________
/*
题目来源: 

http://www.lintcode.com/zh-cn/problem/merge-sorted-array-ii/
*/ 


/*
Merge two given sorted integer array A and B into a new sorted integer array.


Example
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]

Challenge
How can you optimize your algorithm if one array is very large and the other is very small?

*/

// __________________________ Tags __________________________
/*
    Two Pointers , Array
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用STL
// 时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        A.insert(A.end(), B.begin(), B.end());
        sort(A.begin(), A.end());
        return A;
    }
};


// 代码2 - 使用指针 解决

