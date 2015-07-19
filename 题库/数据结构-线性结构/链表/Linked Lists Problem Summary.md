# Linked Lists Problem Summary
 
---
**Definition for singly-linked list:**  

	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	}; 

---
### Iterate Down a List    

**Problem:**  
A very frequent technique in linked list code is to iterate a pointer over all the nodes in a list. Traditionally, this is written as a while loop. The head pointer is copied into a local variable current which then iterates down the list. Test for the end of the list with current!=NULL. Advance the pointer with current=current->next.

**Solution 1:** 
	
	// Return the number of nodes in a list (while-loop version)
	int Length(ListNode* root) {
		int len = 0;
		while(root != nullptr) {
			++len;
			root = root->next;
		}
		return len;
	}
	