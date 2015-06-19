

// __________________________26 - Remove Duplicates from Sorted Array __________________________
/*  题目来源: 
http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array/
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/ 

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,

Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the new length.【超过返回的新数组长度--不用管】

*/

// __________________________ Tags __________________________
/*
	Two Pointers , Array
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n), 空间复杂度O(1)

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        const int size = nums.size();
        if (size == 0)return 0;

        int index = 0;
        for (int i = 1; i < size; ++i) {
            if (nums[i] != nums[index]) nums[++index] = nums[i];  
        }
        
        return index + 1;
    }
};

// c语言版-【不用 加 对空指针的判断】
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1)return numsSize;
        int index = 0;
        for (int i = 1; i < numsSize; ++i) {
            if (nums[i] != nums[index]) {
                nums[++index] = nums[i];
            } 
        }
        return index + 1;
}


// 代码2
// 时间复杂度O(?)，空间复杂度O(?)
class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        return distance(A.begin(), unique(A.begin(), A.end()));
    }
};



// __________________________80 - Remove Duplicates from Sorted Array II __________________________
// 题目来源: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-array-ii/

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 

It doesn't matter what you leave beyond the new length.

*/

// __________________________ Tags __________________________
/*
    Two Pointers , Array
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n), 空间复杂度O(1)

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        const int size = nums.size();
        if (size < 3)return size;

        int index = 0;
        bool same = false;
        for (int i = 1; i < size; ++i) {
            if (!same || nums[i] != nums[index]) {
                nums[++index] = nums[i];
                if (nums[index] == nums[index-1]) {
                    same = true;
                } else {
                    same = false;
                }
            }
        }
        return index + 1;
    }
};
/* 代码1 的 【扩展性】不好，如果重复数允许到 3呢 */


// 代码2
// 时间复杂度O(n)，空间复杂度O(1)
// 可扩展的，这样不管是要求 重复几次都没有关系了。
class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        const int sameMax = 2;      // sameMax 的值 为 1~n
        const int size = nums.size();
        if (size < sameMax + 1)return size;

        int index = 0;
        int sameNum = 1;
        for (int i = 1; i < size; ++i) {
            if (sameNum < sameMax || nums[i] != nums[index]) {
                nums[++index] = nums[i];
                if (nums[index] == nums[index-1]) {
                    ++sameNum;
                } else {
                    sameNum = 1;
                }
            }
        }
        return index + 1;
    }
};
