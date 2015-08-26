


// __________________________ Find the Missing Number __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/find-the-missing-number/

*/  


/*
Given an array contains N numbers of 0 .. N, find which number doesn't exist in the array.


Example
Given N = 3 and the array [0, 1, 3], return 2.

Challenge
Do it in-place with O(1) extra memory and O(n) time.

判断集合中是否存在重复元素或者查找缺失元素是常见编程任务之一，
当集合中数据量比较大时我们通常希望少进行几次扫描，这时双重循环法就不可，位图法Bitmap可以考虑。。

这道题目第二问是：如果缺失俩数、仨数呢？

【一道腾讯前端试题】
题目：有一组数字，从1到n（假设n=10000），从中任意删除了3个数，顺序也被打乱，剩余数字放在一个n-3的数组里，
请找出丢失的数字，要求算法比较快。
*/

// __________________________ Tags __________________________
/*
	 Binary Search, bit-XOR, sum, 交换位置法，Bitmap。
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - sum【累加和法】
// 时间复杂度O(n),空间复杂度O(1)
// 缺点1【受限于空间复杂度】：数据很大时，sum的值 会出现溢出问题，换成 long long 类型都装不下。	 
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int max = nums.size();
        int sum = (1 + max)*max/2 ;
        
        for (int i = 0; i < max; ++i) {
            sum -= nums[i];
        }
        
        return sum;
    }
};

// 代码2 - 遍历【1-先排序，2-再遍历寻找不等于数组下标的那个元素】
// 时间复杂度：【已经排序了的】O(n),	【未排序的】O(nlogn) + O(n)
// 空间复杂度O(1)
// 缺点：不够快。	 
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());	
        int max = nums.size();
        
        for (int i = 0; i < max; ++i) {
            if (nums[i] != i) return i;
        }
        
        return max;
    }
};

// 代码3 - 使用二分法[这个代码待验证]
// 时间复杂度：【已经排序了的】O(logn),	【未排序的】O(nlogn) + O(logn)
// 空间复杂度O(1)
// 缺点：稍微快了一点点。
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());		// 如果未排序就要先排序

        int max = nums.size();

        int mid = max/2;
        int begin = 0;
        int end = max-1;

        while (mid > -1 && mid < max && begin != end) {
        	mid = begin + (end - begin) / 2;
        	if (nums[mid] == mid) {
        		begin = mid + 1;
        	} else {
        		end = mid - 1;
        	}
        }

        return mid;
    }
};


// 代码4 - switch[神奇的交换数据法]
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int max = nums.size();
        
        // 这其实是一种排序过程。
        int lost = -1;
        for (int i = 0; i < max; ++i) {
            while (nums[i] != i && nums[i] != max) {
            	int temp = nums[nums[i]];
            	nums[nums[i]] = nums[i];
            	nums[i] = temp;
            }
            if (nums[i] == max) lost = i;
        }

        if (lost == -1) return max;		// 如果从来没有覆过值， 缺少最大的那个数
        
        return lost;
    }
};


// 代码5 - XOR【异或法】
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int max = nums.size();
        int lost = 0;
        
        for (int i = 0; i < max; ++i) {
            lost ^= nums[i];
            lost ^= i;
        }
        
        return lost;
    }
};

// 代码6 - 【位图法】使用  bitmap 这个扩展性 在用来求 缺失 2个数 和 3个数时更加方便。
// 时间复杂度O(2n),空间复杂度O(n/8)
// 第1次遍历 把数据是否存在放入 bitmap 中，第2次遍历 bitmap中值为0的就是缺少的值。



// 代码7