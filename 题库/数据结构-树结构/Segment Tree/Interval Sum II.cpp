


// __________________________ Interval Sum II __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/interval-sum-ii/

区间求和 II
*/  


/*
Given an integer array in the construct method, implement two methods query(start, end) and modify(index, value):

For query(start, end), return the sum from index start to index end in the given array.
For modify(index, value), modify the number in the given index to value

Example
Given array A = [1,2,7,8,5].

query(0, 2), return 10.
modify(0, 4), change A[0] from 1 to 4.
query(0, 1), return 6.
modify(2, 1), change A[2] from 7 to 1.
query(2, 4), return 14.
Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

Challenge
O(logN) time for query and modify.
*/

// __________________________ Tags __________________________
/*
	 Binary Tree, Segment Tree
*/

// __________________________ 所用到的数据结构 __________________________
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

// __________________________ 实现细节 __________________________ 
// 代码1 - 
// 把前面 刚学会的 建立，改，查，都用到了，好爽。

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
    /* you may need to use some attributes here */
    
    SegmentTreeNodeWithCount *  root;
    
// 提供给测试用的3个接口。    
    /**
     * @param A: An integer vector
     */
    Solution(vector<int> nums) {
        // write your code here
        
        // 构造线段树
        root = build(0, nums.size()-1);
        
        // 线段树-赋值
        for (int i = 0; i < nums.size(); ++i) {
            modifyTree(root, i, nums[i]);
        }
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return queryTree(root, start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        modifyTree(root, index, value);
    }
    
    
private:    
    // 线段树的值查询 - 区间求和
    long long queryTree(SegmentTreeNodeWithCount *root, int start, int end) {
        // write your code here
        // 越界判断
        if(root == nullptr || start > root->end || end < root->start) return 0;
        
        // 重定范围
        if(start < root->start) start = root->start;
        if(end > root->end) end = root->end;
        
        if(start == root->start && end == root->end) return root->count;
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        long long retLeaf = 0;
        if (end <= leftEnd) retLeaf = queryTree(root->left, start, end);
        
        if (start >= rightStart) retLeaf = queryTree(root->right, start, end);
        
        if (start < rightStart && end > leftEnd) {
            retLeaf = queryTree(root->left, start, leftEnd) + queryTree(root->right, rightStart, end);
        }
        
        return retLeaf;
    }
    
    
    // 线段树的值修改 - 区间求和
    long long modifyTree(SegmentTreeNodeWithCount *root, int index, int value) {
        // write your code here
        // if(root == nullptr) return 0;        // 好像没有必要加这句。
        
        // 走到叶子节点。 
        if(index == root->start && index == root->end) {
            root->count = value;
            return root->count;
        }
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        long long retLeft,retRight;
        if (index <= leftEnd) {
            retLeft = modifyTree(root->left, index, value);
            retRight = root->right->count;
        }
        
        if (index >= rightStart) {
            retRight = modifyTree(root->right, index, value);
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
