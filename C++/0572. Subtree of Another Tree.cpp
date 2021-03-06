/**
* Given two non-empty binary trees s and t, check whether tree t has exactly the
* same structure and node values with a subtree of s. A subtree of s is a tree
* consists of a node in s and all of this node's descendants. The tree s could
* also be considered as a subtree of itself.
* Example 1:
* Given tree s:
*	     3
*	    / \
*	   4   5
*	  / \
*	 1   2
*	Given tree t:
*	   4
*	  / \
*	 1   2
*	Return true, because t has the same structure and node values with a subtree of s.
* Example 2:
*	Given tree s:
*	     3
*	    / \
*	   4   5
*	  / \
*	 1   2
*	    /
*	   0
*	Given tree t:
*	   4
*	  / \
*	 1   2
*	Return false.
* https://leetcode.com/problems/subtree-of-another-tree/description/
*
* Author: Adam Yu Wen
* Date: March 20, 2018
*/

// Method 1:
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		string stringS = "", stringT = "";
		inorderTraversal(s, stringS);
		inorderTraversal(t, stringT);
		return stringS.find(stringT) != string::npos;
	}

	void inorderTraversal(TreeNode* t, string &res) {
		// # stands for NULL.
		// Without adding NULLs, the program doesn't work.
		// One string corresponds one unique tree with NULLs.
		if (!t) res += ",#";
		// The else is needed.
		// Because the first line didn't stop the function,
		// when t == NULL
		else {
			res += ("," + to_string(t->val));
			inorderTraversal(t->left, res);
			inorderTraversal(t->right, res);
		}
	}
};

// Method 2:
// Reference: http://www.cnblogs.com/grandyang/p/6828687.html
// It takes 26 ms, which means it is faster than the first method.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s) return false;
		if (isSameTree(s, t)) return true;
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}

	bool isSameTree(TreeNode* s, TreeNode* t) {
		if (!s && !t) return true;
		if (!s || !t) return false;
		if (s->val != t->val) return false;
		return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
	}
};
