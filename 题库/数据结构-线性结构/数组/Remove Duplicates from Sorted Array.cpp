

// 2.1.1 



// __________________________ Remove Duplicates from Sorted Array __________________________
// 题目来源: http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array/
/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Example

Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

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
            if (nums[i] != nums[index])
                nums[++index] = nums[i];
        }
        
        return index + 1;
    }
};


// 代码2
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        return distance(A.begin(), unique(A.begin(), A.end()));
    }
};



// __________________________ Remove Duplicates from Sorted Array II __________________________
// 题目来源: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-array-ii/

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

Example

Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

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


// 代码2
// 时间复杂度O(n)，空间复杂度O(1)

/* 1 的 【扩展性】不好，如果重复数允许到 3呢 */

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
