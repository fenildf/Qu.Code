


// __________________________ Find the Connected Component in the Undirected Graph __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/find-the-connected-component-in-the-undirected-graph/

*/  


/*

Find the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

Have you met this question in a real interview? Yes
Example
Given graph:

A------B  C
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      D   E

Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}

*/

// __________________________ Tags __________________________
/*
	 Breadth First Search
*/

// __________________________ 解题思路 __________________________ 
/*
    1：使用宽度搜索，使用了一个 pool 记录走过的标志位。
*/

// __________________________ 所用到的数据结构 __________________________
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// __________________________ 实现细节 __________________________ 
// 代码1 
// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        
        int i = 0;
        queue<UndirectedGraphNode*> q;          // 使用宽带优先搜索
        q.push(nodes[i]);
        
        vector<vector<int>> mapSum;             // 记录最终返回的结果
        vector<int> map;                        // 记录中间结果    
        vector<UndirectedGraphNode*> pool;      // 记录所有走过的小岛
        
        while (!q.empty()) {
            UndirectedGraphNode* nowNode = q.front();
            q.pop();
            
            int search_value = nowNode->label;
            
            vector<UndirectedGraphNode*>::const_iterator isHaveLook = find(pool.begin(), pool.end(), nowNode);
            if (isHaveLook == pool.end()) {     // 说明没有找到
                map.push_back(search_value);
                pool.push_back(nowNode);
                
                for (int k = 0; k < nowNode->neighbors.size(); ++k) {
                    if (find(pool.begin(), pool.end(), nowNode->neighbors[k]) == pool.end()) {
                        q.push(nowNode->neighbors[k]);
                    }
                }
            }
            
            // 说明一个无向图寻找完成
            if (q.empty()) {
                if (!map.empty()) {
                    sort(map.begin(), map.end());       // 答案要求排序
                    mapSum.push_back(map);
                    map = vector<int> ();               // 重置清零容器
                }
                
                
                ++i;
                if (i < nodes.size()) {                 // 寻找下一个无向图
                    q.push(nodes[i]);
                }
            }
        }
        
        
        return mapSum;
    }
}; 
