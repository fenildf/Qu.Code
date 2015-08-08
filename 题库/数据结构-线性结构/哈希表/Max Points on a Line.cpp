


// __________________________ Copy List with Random Pointer __________________________
/*
题目来源:
https://leetcode.com/problems/max-points-on-a-line/
http://www.lintcode.com/zh-cn/problem/copy-list-with-random-pointer/

最多有多少个点在一条直线上
*/  


/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

// __________________________ Tags __________________________
/*
	 Hash Table, Math
*/

// __________________________ 所用到的数据结构 __________________________
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// __________________________ 实现细节 __________________________ 
// 代码1-遍历每个节点，统计其他节点与当前节点O的斜率，如果斜率相同就是说明都与O在一条直线。
// 时间复杂度O(n^2),额外空间复杂度O(n)。
class Solution {
public:
    int maxPoints(vector<Point>& points) {
       map<double, int> kMap;
        int maxNum = 0;
        
        
        if (points.size() == 1) maxNum = 1;
        
        for (int i = 0; i < points.size(); ++i) {
            kMap.clear();
            // 初始化，要不然当kMap从来没有输入时，下面的统计max大小的那个for循环没法运行。
            kMap[INT_MIN] = 0;  
            
            int duplicate = 1;
                
            
            for(int j = 0; j < points.size(); ++j) {
                if (j == i) continue;   // 跳过自己
                
                // 有2个点的位置一样。
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++duplicate;
                    continue;
                } 

                // 计算出斜率来
                double k = getLineK(points[i], points[j]);
                kMap[k]++;
            }
            
 
            for(map<double, int>::iterator it = kMap.begin(); it != kMap.end(); it++) {
                if (it->second + duplicate > maxNum) maxNum = it->second + duplicate;
            }   
        }
        
        return maxNum; 
    }
    
    // 求出点A和点B的斜率K y = kx + b;
    double getLineK(Point & a1, Point & a2) {
        double k = 0;
        if (a1.x != a2.x) {
            k = (double)(a1.y - a2.y)/(a1.x - a2.x);        // 这里不强制转化的话，进度会损失很多。
        } else {
            k = INT_MAX;    //  INT_MAX是库里里的一个宏定义，它的值等于int类型所能表示的最大的正整数
        }
        
        return k;
    } 
};