﻿


// __________________________ Interval Sum __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/interval-sum/

区间求和 I
*/  


/*
Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the sum number between index start and end in the given array, return the result list.


Example
For array [1,2,7,8,5], and queries [(0,4),(1,2),(2,4)], return [23,9,20]

Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

Challenge
O(logN) time for each query
*/

// __________________________ Tags __________________________
/*
	 Binary Tree, Segment Tree
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
// 代码1 - 
// 把前面 刚学会的 建立，改，查，都用到了，好爽。

// 所用到的数据结构 
// 所用到的数据结构 
class SegmentTreeNodeWithCount {
public:
    int start, end; 
    long long count;
    SegmentTreeNodeWithCount *left, *right;
    SegmentTreeNodeWithCount(int start, int end) {
        count = 0;
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
};

class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &nums, vector<Interval> &queries) {
        // write your code here
        
        // 构造线段树
        SegmentTreeNodeWithCount *  root = build(0, nums.size()-1);
        
        // 线段树-赋值
        for (int i = 0; i < nums.size(); ++i) {
            modify(root, i, nums[i]);
        }
        
        // 统计查询结果
        vector<long long> queryResult(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            queryResult[i] = query(root, queries[i].start, queries[i].end);
        }
        
        return queryResult;
    }
    
    // 线段树的值查询 - 【区间求和】
    long long query(SegmentTreeNodeWithCount *root, int start, int end) {
        // write your code here
        
        if(start == root->start && end == root->end) return root->count;
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        long long retLeaf = 0;
        if (end <= leftEnd) retLeaf = query(root->left, start, end);
        
        if (start >= rightStart) retLeaf = query(root->right, start, end);
        
        if (start < rightStart && end > leftEnd) {
            retLeaf = query(root->left, start, leftEnd) + query(root->right, rightStart, end);
        }
        
        return retLeaf;
    }
    
    
    // 线段树的值修改 - 【区间求和】
    long long modify(SegmentTreeNodeWithCount *root, int index, int value) {
        // write your code here
        
        // 走到叶子节点。 
        if(index == root->start && index == root->end) {
            root->count = value;
            return root->count;
        }
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        long long retLeft,retRight;
        if (index <= leftEnd) {
            retLeft = modify(root->left, index, value);
            retRight = root->right->count;
        }
        
        if (index >= rightStart) {
            retRight = modify(root->right, index, value);
            retLeft = root->left->count;
        }
        
        root->count = retLeft + retRight;
        return root->count;
    }
    
    
    // 线段树的构造
    SegmentTreeNodeWithCount * build(int start, int end) {
        // write your code here
        if(start > end) return (SegmentTreeNodeWithCount *)nullptr;    // 排序树，start <= end
        
        SegmentTreeNodeWithCount *  newNode  = new SegmentTreeNodeWithCount(start, end);
        if (start == end) return newNode;
        
        int leftEnd = (start + end) / 2 ;
        int rightStart = (start + end) / 2 + 1;
        newNode->left   = build(start, leftEnd);
        newNode->right  = build(rightStart, end);
        
        return newNode;
    }
};