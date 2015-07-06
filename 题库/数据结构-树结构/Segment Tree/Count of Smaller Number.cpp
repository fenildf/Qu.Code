


// __________________________ Count of Smaller Number __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/count-of-smaller-number/

区间求和 II
*/  


/*
Medium Count of Smaller Number

21% Accepted
Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) and an query list. For each query, give you an integer, return the number of element in the array that are smaller that the given integer.


Example
For array [1,2,7,8,5], and queries [1,8,5], return [0,4,2]

Note
We suggest you finish problem Segment Tree Build and Segment Tree Query II first.

Challenge
Could you use three ways to do it.

Just loop
Sort and binary search
Build Segment Tree and Search.
*/

// __________________________ Tags __________________________
/*
	 Binary Tree, Segment Tree
*/

// __________________________ 所用到的数据结构 __________________________
// 所用到的数据结构 
class SegmentTreeNodeWithCount {
public:
    int start, end, min, max;
    SegmentTreeNodeWithCount *left, *right;
    SegmentTreeNodeWithCount(int start, int end) {
        min = 0;
        max = 0;
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
};

// __________________________ 实现细节 __________________________ 
// 代码1 - 
// 前面14个用例都通过了，后面一个大数据 直接超时...
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &nums, vector<int> &queries) {
        // write your code here
        // 构造线段树
        SegmentTreeNodeWithCount * root = build(0, nums.size()-1);
        
        // 线段树-赋值
        for (int i = 0; i < nums.size(); ++i) {
            modify(root, i, nums[i]);
        }
        
        // 统计查询结果
        vector<int> queryResult(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            queryResult[i] = query(root, queries[i]);
        }
        
        return queryResult;
    }
    
    // 线段树的值查询  - 【区间中 比 limit 小的值】
    int query(SegmentTreeNodeWithCount *root, int limit) {
        // write your code here
        if (root == nullptr || limit <= root->min) return 0; 
        if (limit > root->max) return root->end - root->start + 1; 
        
         
        int retLeaf = query(root->left, limit) + query(root->right, limit);
 
        return retLeaf;
    }
    
    
    // 线段树的值修改  - 【区间最大值，最小值】
    // 0-最小值，1-最大值。
    void modify(SegmentTreeNodeWithCount *root, int index, int value) {
        // write your code here
        if(root == nullptr) return;
        
        // 走到叶子节点。 
        if(index == root->start && index == root->end) {
            root->max = value;
            root->min = value;
            return;
        }
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        
        if (index <= leftEnd) modify(root->left, index, value);
        if (index >= rightStart) modify(root->right, index, value);

        root->min = min(root->left->min, root->right->min);
        root->max = max(root->left->max, root->right->max);
        
        return;
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