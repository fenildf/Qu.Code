


// __________________________ Next Permutation __________________________
/*
题目来源:
https://leetcode.com/problems/next-permutation/
http://www.lintcode.com/zh-cn/problem/next-permutation-ii/

下一个排列
*/  


/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

// __________________________ Tags __________________________
/*
	 排列，数组
*/

// __________________________ 实现细节 __________________________ 
// 代码1-从后往前遍历，
// 时间复杂度O(n^2),空间复杂度O(1)
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return;   // 只有1个元素的，全排列就是自己。
        
        bool isFind = false;
        int min = nums.size()-2;        // 从后往前遍历,找到一个 min 比 后面的一个元素小，这2个元素之间的区域 重新按照从小到大排列。
        for(int i = min; i > -1 && isFind == false; --i) {
            for(int j = nums.size()-1; j > i; --j) {
                if(nums[j] > nums[i]) {
                    nums[i] ^= nums[j];
                    nums[j] ^= nums[i];
                    nums[i] ^= nums[j];
                    sort(nums.begin()+i+1, nums.end());     // 交换后，本区间 剩下的元素 重新排列。
                    isFind = true;
                    break;
                }
            }
        }
        
        if (isFind == false) reverse(nums.begin(),nums.end());      // 给出排列[4,3,2,1]，其下一个排列是[1,2,3,4]
        
        return;
    }
};




// __________________________ Previous Permutation __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/previous-permuation/

上一个排列
*/  

// __________________________ 实现细节 __________________________ 
// 代码1-还是从后往前遍历，就修改2个地方。 一个 > 改成 < ,一个 从大到小排序。
// 时间复杂度O(n^2),空间复杂度O(1)

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return nums;   // 只有1个元素的，全排列就是自己。
        
        bool isFind = false;
        int min = nums.size()-2;        // 从后往前遍历,找到一个 min 比 后面的一个元素小，这2个元素之间的区域 重新按照从大到小排列。
        for(int i = min; i > -1 && isFind == false; --i) {
            for(int j = nums.size()-1; j > i; --j) {
                if(nums[j] < nums[i]) {
                    nums[i] ^= nums[j];
                    nums[j] ^= nums[i];
                    nums[i] ^= nums[j];
                    sort(nums.begin()+i+1, nums.end(), greater<int>());     // 交换后，本区间 剩下的元素 重新排列，从大到小。
                    isFind = true;
                    break;
                }
            }
        }
        
        if (isFind == false) reverse(nums.begin(),nums.end());
        
        return nums;
    }
};