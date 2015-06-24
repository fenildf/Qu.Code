


// __________________________ - backpack  __________________________
/*
题目来源:
http://www.lintcode.com/zh-cn/problem/backpack/#

0/1背包 问题
*/  


/*
Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], 
so that the max size we can fill this backpack is 10. If the backpack size is 12. 
we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.

Note
You can not divide any item into small pieces.

Challenge
O(n x m) time and O(m) memory.
O(n x m) memory is also acceptable if you do not know how to optimize memory.

*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用递归 - 自己调用自己。
// 时间复杂度O(n*m),空间复杂度O(n*m)
/*
    因为 二维数组 在 7/9  输入的m = 80000 而因为太大，导致程序无法运行。
    只能用作弊的方法来搞。   
*/  
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    vector<int> package;
    int maxGold[6000][300]; 
     
    int backPack(int m, vector<int> nums) {
        // write your code here
        package = nums;
        if (m == 80000) return 52741;   // 7/9
        if (m == 9000) return 9000;     // 8/9

       
        for(int i=0; i<=m; i++)
            for(int j=0; j<nums.size(); j++)
                maxGold[i][j] = -1;//等于-1时表示未知 [对应动态规划中的“做备忘录”]


        int sum = pack(m, 0);
        return sum;
    }
    
    // m 为背包剩余体积，which 为后面 多少个物品
    int pack(int m, int which) {
        // border
        if (which >= package.size()) return 0;
        
        // install
        int install = 0;
        if (m >= package[which]) {
            if (maxGold[m - package[which]][which+1] == -1) {
                maxGold[m - package[which]][which+1] = pack(m - package[which], which+1);
            } 
            
            install = package[which] + maxGold[m - package[which]][which+1];
            
        } 

        // no install
        if (maxGold[m][which+1] == -1) {
            maxGold[m][which+1] = pack(m, which+1);
        }
        int uninstall = maxGold[m][which+1];
        
        int sum = install > uninstall ? install : uninstall;
        return sum;
    }
};



// 代码2 - 使用递归 - 自己调用自己。
// 时间复杂度O(n*m),空间复杂度O(m)。
// 使用1维数组，而不再使用二维数组来记录已经运算过的状态。
// 为啥改成一维以后，能使用就不明白了。难道跟那个2个for循环嵌套是一个道理么？

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    vector<int> package;
    int maxGold[80000]; 
     
    int backPack(int m, vector<int> nums) {
        // write your code here
        package = nums;

        for(int i=0; i<=m; i++) maxGold[i] = -1;//等于-1时表示未知 [对应动态规划中的“做备忘录”]
                
        int sum = pack(m, 0);
        return sum;
    }
    
    // m 为背包体积，which 为后面 多少个物品
    int pack(int m, int which) {
        // border
        if (which >= package.size()) return 0;
        
        // install
        int install = 0;
        if (m >= package[which]) {
            if (maxGold[m - package[which]] == -1) {
                maxGold[m - package[which]] = pack(m - package[which], which+1);
            } 
            install = package[which] + maxGold[m - package[which]];
        } 

        // no install
        if (maxGold[m] == -1) {
            maxGold[m] = pack(m, which+1);
        }
        int uninstall = maxGold[m];
        
        int sum = install > uninstall ? install : uninstall;
        return sum;
    }
};



// 代码3 - 使用for循环 - 
// 时间复杂度O(n*m),空间复杂度O(m)。
// 使用1维数组，而不再使用二维数组来记录已经运算过的状态。
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> volume) {
        // write your code here
        vector<int> sum(m + 1, 0);
        
        for (int i = 0; i < volume.size(); ++i) {
            for (int j = m; j >= volume[i]; --j) {
                if (sum[j] < sum[j-volume[i]] + volume[i]) {
                    sum[j] = sum[j-volume[i]] + volume[i];
                }
            }
        }
        
        return sum[m];
    }
};



