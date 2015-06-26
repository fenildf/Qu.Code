


// __________________________ Container With Most Water __________________________
/*
题目来源:

http://www.lintcode.com/zh-cn/problem/container-with-most-water/
https://leetcode.com/problems/container-with-most-water/
装最多水的容器
*/  


/*


*/

// __________________________ Tags __________________________
/*
	 两根指针，数组
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用1个for循环  
// 时间复杂度O(n),空间复杂度O(1)。
/*
    1-取前面和末端2个元素 算出一个体积maxV，
    2-然后对比该2元素，小的就往中间移动
    3-重复第2步
    
    局部最优解-是全局最优解。
*/     
    
class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        
        // 容错处理
        if (heights.size() < 1) return 0;
        
        // 初始化
        int start = 0;
        int end = heights.size() - 1;
        int maxV = 0;
        
        while(start < end) {
            int v = (end - start) * min(heights[start], heights[end]);
            maxV = max(v, maxV);
            
            if (heights[start] < heights[end]) {
                ++start;
            } else {
                --end;
            }
        }
        return maxV;
    }
};
