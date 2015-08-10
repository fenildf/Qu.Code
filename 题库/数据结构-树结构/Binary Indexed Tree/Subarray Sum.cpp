


// __________________________ Subarray Sum  __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/subarray-sum/

子数组之和
*/  


/*
Given an integer array, find a subarray where the sum of numbers is zero. 
Your code should return the index of the first number and the index of the last number.


Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].

Note
There is at least one subarray that it's sum equals to zero.
*/

// __________________________ Tags __________________________
/*
	 BIT,
*/

// __________________________ 所用到的数据结构 __________________________


// __________________________ 实现细节 __________________________ 
// 代码1 - 暴力版，如果数组很大，肯定会超时
// 时间复杂度O(n^2)
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                
                if (sum == 0){
                    vector<int> re = {i, j};
                    return re;
                }
            }
        }
    }
};

// 代码2 - 使用树状数组
// 时间复杂度O()
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> treeNum;
     
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        
        // 树状数组--实现公式
        buildTreeNum(nums);
        
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum = getSegmentSum(i+1, j+1);
                
                if (sum == 0){
                    vector<int> re = {i, j};
                    return re;
                }
            }
        }
        
    }
    
    int lowBit(int i)   // 将i中最后的1分离出来
    {  
        return i & (i ^ (i - 1));  
    }
    
    // 生成树状数组
    void buildTreeNum(vector<int> & nums) {
        treeNum.push_back(0);   // 树状数组从1开始，所以先压入一个值
        int sum = 0;
        for (int i = 1; (i - 1) < nums.size(); ++i) {
            sum = nums[i-1];
            for (int j = i - 1; j > i - lowBit(i); j -= lowBit(j)) {
                sum += treeNum[j];
            }
            treeNum.push_back(sum); 
        }
    }
    
    // 求1~X的和
    int getSum(int x) {  
        int sum = 0;  
        while(x){  
            sum += treeNum[x];  
            x -= lowBit(x);  
        }  
        return sum;  
    }
    
    // 求 i~j之间的和 [i 可以等于 j]
    int getSegmentSum(int i, int j) {
        int s1;
        if (i > 1) {
            s1 = getSum(i-1);
        } else if (i == 1) {
            s1 = 0;
        }
        
        int s2 = getSum(j);
        
        return s2 - s1;
    }
};
