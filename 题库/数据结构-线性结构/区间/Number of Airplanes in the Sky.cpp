


// __________________________ Number of Airplanes in the Sky  __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/number-of-airplanes-in-the-sky/

*/  


/*
Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?


Example
For interval list [[1,10],[2,3],[5,8],[4,7]], return 3

Note
If landing and flying happens at the same time, we consider landing should happen at first.
*/

// __________________________ Tags __________________________
/*
	 Interval; Array
*/


// __________________________ 所用到的数据结构 __________________________
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */


// __________________________ 实现细节 __________________________ 

// 代码1-暴力遍历法。
// 时间复杂度O(n*m),空间复杂度O(n)
 // 最后运行时间 8000ms,勉勉强强通过。
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        
        vector<int> time(1120500,0); // 初始化 记录容器
        
        for (int i = 0; i < airplanes.size(); ++i) {
            int start = airplanes[i].start;
            int end = airplanes[i].end;
            for(int j = start + 1; j <= end; ++j) { // 降落有优先权,所以 j = start + 1;
                ++time[j];
            }
        }
        
        sort(time.begin(), time.end());
        return time[time.size()-1];
    }
};

// 代码2-应该有更加聪明的办法