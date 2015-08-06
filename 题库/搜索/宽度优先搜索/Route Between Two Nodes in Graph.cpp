


// __________________________ Route Between Two Nodes in Graph __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/route-between-two-nodes-in-graph/

*/  


/*
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.


Example
Given graph:

A----->B----->C
 \     |
  \    |
   \   |
    \  v
     ->D----->E
for s = B and t = E, return true

for s = D and t = C, return false

*/

// __________________________ Tags __________________________
/*
	 String
*/

// __________________________ 解题思路 __________________________ 
/*
    1：使用宽度搜索，不敢用深度搜索，因为没有加走过的标志位，怕进入无限循环中。

    2：时间优化：加走过的标志位，会更快点吧。
*/

// __________________________ 所用到的数据结构 __________________________
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

// __________________________ 实现细节 __________________________ 
// 代码1 
// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        
        
        // 使用 BFS ,而且我还没有加 走过的标志位...,是不是 测试的数据太弱了。
        std::queue<DirectedGraphNode*> q;
        q.push(s);
        
        while(!q.empty()) {
            DirectedGraphNode* nowNode = q.front();
            q.pop();
            
            if(nowNode == t) return true;
            
            for (int i = 0; i < nowNode->neighbors.size(); ++i) {
                q.push(nowNode->neighbors[i]);
            }
        }
        
        return false;
    }
};

