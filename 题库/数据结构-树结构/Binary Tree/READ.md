


## TREE

### Check if Two Trees are Identical

**Problem:**  
Given two binary trees, write a function to check if they are equal or not.

**Solution:**   
Two binary trees are considered equal if they are structurally identical andthe nodes have the same value.

**Hint:**   
Depth first traversal

**Solution 1:**   

	bool are_identical(TreeNode *root1, TreeNode *root2) {
		if (root1 == nullptr && root2 == nullptr) {
			return true;
		}
		
		if (root1 != nullptr && root2 != nullptr) {
			return ((root1->val == root2->val) && 
			are_identical(root1->left, root2->left) && 
			are_identical(root1->right, root2->right));
		}
		
		return false;
	}