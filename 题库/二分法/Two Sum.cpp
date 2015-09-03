


// __________________________ Two Sum   __________________________
/*
题目来源:
http://www.lintcode.com/submission/1467308/
https://leetcode.com/problems/two-sum/

两数之和
*/  


/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

// __________________________ Tags __________________________
/*
	 Binary Search
*/

// __________________________ 实现细节 __________________________ 
// 代码1 - 暴力搜索法
// 时间复杂度O(N*N),     在 leetcode 上面会因为超时，而没有办法 AC的。
// 空间复杂度O(n)     
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        
        vector<int> pool;
        for (int i = 0; i < nums.size(); ++i) {
            int midTar;
            midTar = target - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (midTar == nums[j]) {
                    pool.push_back(i+1);
                    pool.push_back(j+1);
                    
                    return pool;
                }
            }
        }
    }
};


// 代码2 - 使用二分法
// 时间复杂度O(nlog(n)排序 + nlog(n)二分查找 + n确定位置),
// 空间复杂度O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pool = nums;
        
        sort(pool.begin(), pool.end());
        
        int i;
        for (i = 0; i < nums.size(); ++i) {
            int midTar;
            midTar = target - pool[i];
            if (binary_search(pool.begin(), pool.end(), midTar)) {
                break;
            }
        }
        
        // 找到要查找的数了。
        int a = pool[i];
        int b = target - pool[i];
        
        // 接下来确定 A 和 B 在 nums中的位置。
        vector<int> res;
        for(int j = 0; j < nums.size(); ++j) {
            if(nums[j] == a || nums[j] == b) {
                if (res.size() == 0) {
                    res.push_back(j+1);
                } else if (nums[j] + nums[res[0]-1] == target) {    // 找对值了
                    res.push_back(j+1);
                    break;
                }
            }
        }
        
        return res;
    }
};


// __________________________    __________________________
/*
题目来源:



*/  


/*

*/

class Solution {
