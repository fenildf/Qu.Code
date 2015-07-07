


// __________________________ Partition Array by Odd and Even __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/partition-array-by-odd-and-even/

*/  


/*
Partition an integers array into odd number first and even number second.


Example
Given [1, 2, 3, 4], return [1, 3, 2, 4]

Challenge
Do it in-place.
*/

// __________________________ Tags __________________________
/*
	 Array, 
*/

// __________________________ 实现细节 __________________________ 

// 代码1-使用STL
// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1 == 1) {
                odd.push_back(nums[i]);
            } else {
                even.push_back(nums[i]);
            }
        }
        odd.insert(odd.end(), even.begin(), even.end());
        nums = odd;
    }
};


// 代码2-使用2根指针，原地翻转。