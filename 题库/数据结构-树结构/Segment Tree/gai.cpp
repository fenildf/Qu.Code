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
    
    // 线段树的值查询  - 【区间最小值】
    int query(SegmentTreeNodeWithCount *root, int limit) {
        // write your code here
        
        if(limit == root->start && limit == root->end) return root->max;
        
        int leftEnd = (root->start + root->end) / 2 ;
        int rightStart = (root->start + root->end) / 2 + 1;
        
        int retLeaf = 0;
        if (limit <= leftEnd) retLeaf = query(root->left, limit, limit);
        
        if (limit >= rightStart) retLeaf = query(root->right, limit, limit);
        
        if (limit < rightStart && end > leftEnd) {
            retLeaf = min(query(root->left, limit, leftEnd), query(root->right, rightStart, limit));
        }
        
        return retLeaf;
    }
    
    
    // 线段树的值修改  - 【区间最大值，最小值】
    // 0-最小值，1-最大值。
    void modify(SegmentTreeNodeWithCount *root, int index, int value) {
        // write your code here
        
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