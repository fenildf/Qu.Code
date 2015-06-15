
// 想不出来 高效的版本，先放着吧。


// __________________________ Best Time to Buy and Sell Stock __________________________
// 题目来源: http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Example

Given an example [3,2,3,1,2], return 1

*/

// __________________________ Tags __________________________
/*
	贪心 ,枚举法， Array
*/

// __________________________ 实现细节 __________________________ 

// 代码1[穷举法]
// 时间复杂度O(n^2), 空间复杂度O(1)
// 运行后直接超时...  超过 1010ms
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        const int size = prices.size();
        if (size < 2)return 0;
        
        // 暴力枚举法
        int buy, sell, maxprofit = 0;
        for (int i = 0; i < size - 1; ++i) {
            buy = prices[i];
            for (int j = i+1; j < size; ++j) {
                sell = prices[j];
                if (sell - buy > maxprofit) {
                    maxprofit = sell - buy;
                }
            }
        }
        
        return maxprofit;
    }
};


// 代码2[改进后的穷举法]
// 时间复杂度O(n++)，空间复杂度O(1)

// 还是运行超时
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        const int size = prices.size();
        if (size < 2)return 0;
        
        // 暴力枚举法
        int buy = 0, sell = size - 1, maxprofit = 0;
        int origin = 0;
        
        do {
            // 寻找卖点
            for (int j = size - 1; j > origin; --j) {
                if (prices[j] > prices[sell]) sell = j;
            }
            
            // 寻找买点
            for (int i = origin; i < sell; ++i) {
                if (prices[buy] > prices[i]) buy = i;
            }
            
            // 计算收益
            if (prices[sell] - prices[buy] > maxprofit) {
                maxprofit = prices[sell] - prices[buy];
            }
            
            origin = sell + 1;
            sell = size - 1;
            buy = origin;
        }while(origin < size - 1);
        
        return maxprofit;

        
    }
};

[10000,9999,9998,9997,9996,9995,9994,9993,9992,9991,9990,9989,9988,9987,9986,9985,9984,9983,9982,9981,9980,9979,
9978,9977,9976,9975,9974,9973,9972,9971,9970,9969,9968,9967,9966,9965,9964,9963,9962,9961,9960,9959,9958,9957,
9956,9955,9954,9953,9952,9951,9950,9949,9948,9947,9946,9945,9944,9943,9942,9941,9940,9939,9938,9937,9936,9935,
9934,9933,9932,9931,9930,9929,9928,9927,9926,9925,9924,9923,9922,9921,9920,9919,9918,9917,9916,9915,9914,9913,
9912,9911,9910,9909,9908,9907,9906,9905,9904,9903,9902,9901,9900,9899,9898,9897,9896,9895,9894,9893,9892,9891,
9890,9889,9888,9887,9886,9885,9884,9883,9882,9881,9880,9879,9878,9877,9876,9875,9874,9873,9872,9871,9870,9869,
9868,9867,9866,9865,9864,9863,9862,9861,9860,9859,9858,9857,9856,9855,9854,9853,9852,9851,9850,9849,9848,9847,
9846,9845,9844,9843,9842,9841,9840,9839,9838,9837,9836,9835,9834,9833,9832,9831,9830,9829,9828,9827,9826,9825,
9824,9823,9822,9821,9820,9819,9818,9817,9816,9815,9814,9813,9812,9811,9810,9809,9808,9807,9806,9805,9804,9803,
9802,9801,9800,9799,9798,9797,97 ...

// 遇到这种递减的数据，上面的 代码2 就会做很多无用功。


// 代码3
// 改进1：先寻找 买点，再寻找卖点。【专门对付这种一路递减的数据】
// 【运行时间大大缩短：41ms，但是居然返回收益值为0.无法对付 闪电型 递减曲线】
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        const int size = prices.size();
        if (size < 2)return 0;
        
        // 暴力枚举法
        int buy = 0, sell = size - 1, maxprofit = 0;
        int origin = 0;
        
        do {
            // 寻找买点
            for (int i = origin; i < size - 1; ++i) {
                if (prices[buy] > prices[i]) buy = i;
            }
            
            // 寻找卖点
            for (int j = size - 1; j > buy; --j) {
                if (prices[j] > prices[sell]) sell = j;
            }
            
            // 计算收益
            if (prices[sell] - prices[buy] > maxprofit) {
                maxprofit = prices[sell] - prices[buy];
            }
            
            origin = sell + 1;
            sell = size - 1;
            buy = origin;
        }while(origin < size - 1);
        
        return maxprofit;
    }
};

// 代码4
// 改进1：【闪电型递减 曲线 改如何对付】利用 拐点 来寻找 买入点。
// 三个连续的点的关系就只有 4种。 斜着上升，斜着下降， 上升又下降，下降又上升。
// 我们就是要 寻找 下降又上升 这个点 为买进点。

// 还是 超时。
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        const int size = prices.size();
        if (size < 2)return 0;
        
        // 暴力枚举法
        int buy = 0, sell = 0, maxprofit = 0;
        int origin = 0;
        bool repeat = false;
        int lowbuy = 0;
        
        do {
            
            // 寻找买点
            for (int i = origin; i < size - 2; ++i) {
                // 寻找拐点。
                if (prices[i+1] > prices[i] && (i == 0 || prices[i-1] > prices[i])) {
                    
                    // 这种拐点不要
                    if(sell != 0 && i < sell && prices[i] >= prices[lowbuy]) continue;
                    
                    buy = i;
                    break;
                } 
                
            }
            
            if (sell > buy) {
                repeat = true;
            } else {
                repeat = false;
            }
        
            // 寻找卖点
            if (repeat == false) {
                sell = size - 1;
                for (int j = buy + 1; j < size; ++j) {
                    if (prices[j] > prices[sell]) sell = j;
                }
            }
            
            
            // 计算收益
            if (prices[sell] - prices[buy] > maxprofit) {
                maxprofit = prices[sell] - prices[buy];
            }
            
            lowbuy = buy;
            origin = buy + 1;
            buy = origin;

        }while(origin < size - 2);
        
        return maxprofit;
        
        
    }
};

