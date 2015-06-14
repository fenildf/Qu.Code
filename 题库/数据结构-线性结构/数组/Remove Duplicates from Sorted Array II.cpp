

// 2.1.1 

// 题目来源: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-array-ii/

// __________________________ Remove Duplicates from Sorted Array II __________________________
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

/* 好像1 的扩展性不好，如果重复数允许到 3呢 */



