


// __________________________ 3Sum   __________________________
/*
题目来源:
https://leetcode.com/problems/3sum/
http://www.lintcode.com/zh-cn/problem/3-sum/

三数之和
*/  


/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

// __________________________ Tags __________________________
/*
	 Binary Search
*/

// __________________________ 实现细节 __________________________ 
// 代码1 - 二叉搜索法
// 时间复杂度O(?),     在 leetcode 上面会因为超时，而没有办法 AC的。
// 空间复杂度O(n)     
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int>> resPool;
        for (int i = 0; i < nums.size(); ++i) {
            int target = 0 - nums[i];
            vector<int> numSon = nums;
            numSon.erase(numSon.begin() + i);    // 把第1个元素从池子里面拿出去
            vector<vector<int>> restultPool = twoSum(numSon, target);
            for (int j = 0; j < restultPool.size(); ++j) {
                vector<int> res = restultPool[j];
                if (res.size() == 3) {
                    // 检查已存 数组 里面是否有重复的数组。  
                    if (!isContainVector(resPool, res)) resPool.push_back(res);
                }
            }
        }
        
        return resPool;
    }
    
    // 所有传入的对比数组 必须是 已经排序的。
    bool isContainVector(vector<vector<int>> &pool, vector<int> &nums) {
        for (int j = 0; j < pool.size(); ++j) {
            if(isTwoVectorEqual(pool[j], nums)) {
               return true;
            }
        }
        
        return false;   // 说明 pool 里面没有包含 nums
    }
    
    // 所有传入的对比数组 必须是 已经排序的。
    bool isTwoVectorEqual(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() != nums2.size()) return false;
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] != nums2[i]) return false;
        }
        
        return true;
    }
    
    
    void deleteNum(vector<int> &nums, int goal) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == goal) {
                nums.erase(nums.begin() + i);
            }
        }
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        vector<int> pool = nums;
        
        sort(pool.begin(), pool.end());
        
        int i;
        vector<vector<int>> restultPool;
        
        for (i = 0; i < nums.size(); ++i) {
            int midTar;
            midTar = target - pool[i];
            vector<int> poolSon = pool;
            poolSon.erase(poolSon.begin() + i);       // 把第2个元素从池子里面拿出去
            if (binary_search(poolSon.begin(), poolSon.end(), midTar)) {
                vector<int> res;
                res.push_back(midTar);
                res.push_back(pool[i]);
                res.push_back(-target);
                sort(res.begin(), res.end());
                restultPool.push_back(res);
            }
        }

        return restultPool;
    }
};


// 代码1 - 
// 时间复杂度O(?),     进行了优化的。 还是不行。
// 空间复杂度O(n)  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 记录返回结果的池子
        vector<vector<int>> resPool;
        
        sort(nums.begin(), nums.end()); 
        
        // 从原数组中 只每样挑一个出来检查。
        vector<int> removeRepeat = nums;       
        removeRepeat.erase(unique(removeRepeat.begin(), removeRepeat.end()), removeRepeat.end());
        
        // 开始检测
        for (int i = 0; i < removeRepeat.size(); ++i) {
            int target = 0 - removeRepeat[i];
            vector<int> numSon = nums;
            deleteNum(numSon, removeRepeat[i]);     // 把第1个元素从池子里面拿出去
   
            vector<vector<int>> restultPool = twoSum(numSon, target);
            for (int j = 0; j < restultPool.size(); ++j) {
                vector<int> res = restultPool[j];
                if (res.size() == 3) {
                    // 检查已存 数组 里面是否有重复的数组。  
                    if (!isContainVector(resPool, res)) resPool.push_back(res);
                }
            }
        }
        
        return resPool;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        vector<int> pool = nums;
        
        //sort(pool.begin(), pool.end());
        vector<int> removeRepeat = nums;       
        removeRepeat.erase(unique(removeRepeat.begin(), removeRepeat.end()), removeRepeat.end());
        
        int i;
        vector<vector<int>> restultPool;
        
        for (i = 0; i < removeRepeat.size(); ++i) {
            int midTar;
            midTar = target - removeRepeat[i];
            vector<int> poolSon = pool;
            deleteNum(poolSon, removeRepeat[i]);
            //poolSon.erase(poolSon.begin() + i);       // 把第2个元素从池子里面拿出去
            
            if (binary_search(poolSon.begin(), poolSon.end(), midTar)) {
                vector<int> res;
                res.push_back(midTar);
                res.push_back(pool[i]);
                res.push_back(-target);
                sort(res.begin(), res.end());
                restultPool.push_back(res);
            }
        }
        
        return restultPool;
    }
    
    // 所有传入的对比数组 必须是 已经排序的。
    bool isContainVector(vector<vector<int>> &pool, vector<int> &nums) {
        for (int j = 0; j < pool.size(); ++j) {
            if(isTwoVectorEqual(pool[j], nums)) {
               return true;
            }
        }
        
        return false;   // 说明 pool 里面没有包含 nums
    }
    
    // 所有传入的对比数组 必须是 已经排序的。
    bool isTwoVectorEqual(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() != nums2.size()) return false;
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] != nums2[i]) return false;
        }
        
        return true;
    }
    
    // 删除发现的第一个元素。
    void deleteNum(vector<int> &nums, int goal) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == goal) {
                nums.erase(nums.begin() + i);
            }
        }
    }
};

// __________________________    __________________________
/*
题目来源:



*/  


/*

*/

class Solution {
