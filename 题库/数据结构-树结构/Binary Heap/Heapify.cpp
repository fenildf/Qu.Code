


// __________________________ Heapify __________________________
/*
题目来源:
http://www.lintcode.com/en/problem/heapify/

堆化
*/  


/*
Given an integer array, heapify it into a min-heap array.

For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

Example
Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.

Challenge
O(n) time complexity

Clarification
What is heap?

Heap is a data structure, which usually have three methods: push, pop and top. where "push" add a new element the heap, "pop" delete the minimum/maximum element in the heap, "top" return the minimum/maximum element.

What is heapify?
Convert an unordered integer array into a heap array. If it is min-heap, for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].

What if there is a lot of solutions?
Return any of them.

*/

// __________________________ Tags __________________________
/*
	 Dynamic Programming-动态规划;
*/

// __________________________ 实现细节 __________________________ 

// 代码1 - 使用数组实现堆，依次取出每个数据来放入新建的堆中，然后堆化。 
// 时间复杂度O(nlogn),空间复杂度O(n)。

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    vector<int> heap; 
    void heapify(vector<int> &nums) {
        // write your code here
        for (int i = 0; i < nums.size(); ++i) {
            push(nums[i]);
        }
        nums = heap;
    }
    
    void push(int x) {
        heap.push_back(x);
        
        int p = heap.size() - 1;
        
        while(p > 0) {
            int father = (p-1)/2;   // 计算出 父节点 索引值
            
            if (heap[father] < heap[p]) break;
            
            swap(heap[father], heap[p]);
            
            p = father;
        }
    }
};


