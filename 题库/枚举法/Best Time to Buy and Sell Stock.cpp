// __________________________ Best Time to Buy and Sell Stock   __________________________
/*
题目来源:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock/
买卖股票的最佳时机
*/  


/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
*/

// __________________________ Tags __________________________
/*
	 Enumeration
*/

// __________________________ 实现细节 __________________________ 
// 代码1 - 
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // write your code here
        int buyDate,sellDate;
        int date = 0;
        vector<int> buyPool;
        vector<int> sellPool;
        
        // 把所有的 买入 和 卖出 都写入数组
        while (date < prices.size()) {
            // 买入
            buyDate = findBuy(prices, date);
            if(buyDate == prices.size() - 1) break; // 最后一天了，没法卖出了。
            buyPool.push_back(prices[buyDate]);
            
            // 卖出
            sellDate = findSell(prices, buyDate + 1);
            sellPool.push_back(prices[sellDate]);
            
            date = sellDate + 1;
        }
        
        // 从池子中刷选出 合适的 买入 和 卖出点。
        int maxProfit = 0;
        int beganID = 0;
        int sellID, buyID;
        
        if(buyPool.size() == 0) return maxProfit;
        
        while (beganID < sellPool.size()) {
            sellID = find(sellPool, beganID, sellPool.size(), true);    // 查找最大值
        
            buyID = find(buyPool, beganID, sellID + 1, false);          // 边界值是比 sellID 大1
            maxProfit = max(maxProfit, sellPool[sellID] - buyPool[buyID]);  // 计算差值
            beganID = sellID + 1;
        }
        
        return maxProfit;
    }
    
    int find(vector<int>& pool, int begin, int end, bool isMax) {
        int mm = pool[begin];
        int whichOne = begin;
        for (int i = begin; i < end; ++i) {
            if ((pool[i] > mm) == isMax) {
                mm = pool[i];
                whichOne = i;
            }
        }
        
        return whichOne;
    }
    
    
    int findBuy(vector<int>& prices, int i) {       // 寻找一个BUY-DATE
        while (i + 1 < prices.size() && prices[i] >= prices[i+1]) {
            ++i;
        }
        
        return i;
    }
    
    int findSell(vector<int>& prices, int i) {       // 寻找一个SELL-DATE
        while (i < prices.size()-1) {
            if (i + 1 < prices.size() && prices[i] > prices[i+1]) break;
            ++i;
        }
        
        return i;
    }
};


// __________________________ Best Time to Buy and Sell Stock II __________________________
/*
题目来源:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-ii/#

买卖股票的最佳时机 II
*/  


/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

// __________________________ Tags __________________________
/*
     Enumeration
*/

// __________________________ 实现细节 __________________________ 
// 代码1
// 时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int>& prices) {
        int buy,sell,buyDate,sellDate;
        int date = 0;
        int profit = 0;
        
        while (date < prices.size()) {
            // 买入
            buyDate = findBuy(prices, date);
            buy = prices[buyDate];
            
            if(buyDate == prices.size() - 1) break; // 最后一天了，没法卖出了。
            
            // 卖出
            sellDate = findSell(prices, buyDate + 1);
            sell = prices[sellDate];
            profit += (sell - buy);
            
            date = sellDate + 1;
        }
        
        return profit;
    }
    
    int findBuy(vector<int>& prices, int i) {       // 寻找一个BUY-DATE
        while (i + 1 < prices.size() && prices[i] >= prices[i+1]) {
            ++i;
        }
        
        return i;
    }
    
    int findSell(vector<int>& prices, int i) {       // 寻找一个SELL-DATE
        while (i < prices.size()-1) {
            if (i + 1 < prices.size() && prices[i] > prices[i+1]) break;
            ++i;
        }
        
        return i;
    }
};