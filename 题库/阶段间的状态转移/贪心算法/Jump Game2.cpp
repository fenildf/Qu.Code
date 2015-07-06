


// __________________________ Jump Game2 __________________________
/*
题目来源:
https://leetcode.com/problems/jump-game-ii/
http://www.lintcode.com/zh-cn/problem/jump-game-ii/

跳跃游戏2
*/  


/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*/

// __________________________ Tags __________________________
/*
	 Greedy-贪心法;
     每个阶段的最优状态都是由上一个阶段的最优状态得到的->贪心；
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用2个for循环,我感觉我这个也是 贪心算法啊。  
// 时间复杂度O(n*m),空间复杂度O(m)。
// 使用了2个1维数组-记录以前的状态。把能走到最后位置的元素压入 index，同时把他们所需的最小步数 压入 step
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> nums) {
        // wirte your code here
        int borad = nums.size()-1;           // 初始时最优状态就是最后一个元素。
        
        // 记录 能到达数组最后一个位置的元素，所需的 步数。
        vector<int> step;       // 记录所需步数
        vector<int> index;      // 记录在数组中的位置
        
        for (int i = nums.size()-1; i >= 0; --i) {   
            // 1-到达上一个阶段的最优状态,说明可以到达数组最后一个位置
            if (i + nums[i] >= borad) {     
                borad = i;                  // 2-如果能到达，i就变成现在这个阶段的最优状态。
                
                // 开始计算需要几步
                int minStep = (step.size() == 0) ? 0 : step.back() + 1;
                
                for (int j = index.size()-1; j >= 0; --j) { // 遍历 index
                    if ( i + nums[i] >= index[j]) {
                        minStep = (step[j] + 1 < minStep) ? step[j] + 1 : minStep;
                    } else {
                        break;
                    }
                }
                
                index.push_back(i);
                step.push_back(minStep);
            }
        }
        
        return step.back();
    }
};

/*
在 lintcode 网站，上面的代码就 跑最后一个数据时，超时了。

Input:
[1,10000,9999,9998,9997,9996,9995,9994,9993,9992,9991,9990,9989,9988,9987,9986,9985,9984,9983,9982,9981,9980,9979,9978,9977,9976,9975,9974,9973,9972,9971,9970,
9969,9968,9967,9966,9965,9964,9963,9962,9961,9960,9959,9958,9957,9956,9955,9954,9953,9952,9951,9950,9949,9948,9947,9946,9945,9944,9943,9942,9941,9940,9939,9938,
9937,9936,9935,9934,9933,9932,9931,9930,9929,9928,9927,9926,9925,9924,9923,9922,9921,9920,9919,9918,9917,9916,9915,9914,9913,9912,9911,9910,9909,9908,9907,9906,
9905,9904,9903,9902,9901,9900,9899,9898,9897,9896,9895,9894,9893,9892,9891,9890,9889,9888,9887,9886,9885,9884,9883,9882,9881,9880,9879,9878,9877,9876,9875,9874,
9873,9872,9871,9870,9869,9868,9867,9866,9865,9864,9863,9862,9861,9860,9859,9858,9857,9856,9855,9854,9853,9852,9851,9850,9849,9848,9847,9846,9845,9844,9843,9842,
9841,9840,9839,9838,9837,9836,9835,9834,9833,9832,9831,9830,9829,9828,9827,9826,9825,9824,9823,9822,9821,9820,9819,9818,9817,9816,9815,9814,9813,9812,9811,9810,
9809,9808,9807,9806,9805,9804,9803,9802,9801,9800,9799,9798,9797, ...

Output:
3
*/


//  代码2 - 贪心 算法 -改进版
/*
    加了个 if 判断，发现有元素覆盖的区域时，就跳过不再检测。
*/  
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int borad = nums.size()-1;           // 初始时最优状态就是最后一个元素。
        
        // 记录 能到达数组最后一个位置的元素，所需的 步数。
        vector<int> step;       // 记录所需步数
        vector<int> index;      // 记录在数组中的位置
        
        for (int i = nums.size()-1; i >= 0; --i) {   
            // 1-到达上一个阶段的最优状态,说明可以到达数组最后一个位置
            if (i + nums[i] >= borad) {     
                borad = i;                  // 2-如果能到达，i就变成现在这个阶段的最优状态。
                
                // 开始计算需要几步
                int minStep = (step.size() == 0) ? 0 : step.back() + 1;
                
                for (int j = index.size()-1; j >= 0; --j) { // 遍历 index
                    if ( i + nums[i] >= index[j]) {
                        minStep = (step[j] + 1 < minStep) ? step[j] + 1 : minStep;
                    } else {
                        break;
                    }
                    
                    // 如果两个元素覆盖的区域的右边界相等，就可以跳过了。
                    if (nums[i] == nums[index[j]] + (index[j] - i)) {
                        minStep = (step[j] < minStep && step[j] != 0) ? step[j] : minStep;
                        break;
                    } 
                }
                
                index.push_back(i);
                step.push_back(minStep);
            }
        }
        
        return step.back();
    }
};
