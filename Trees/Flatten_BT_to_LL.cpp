// Problem Link -> https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// * Just point the left subtree of every node to the right of current node

class Solution{
public:
	void flatten(TreeNode* root){
		TreeNode* curr;

		while(curr){
	
			if(curr->left){
				TreeNode* node = curr->left;
				while(node->right){
					node = node->right;
				}

				node->right = curr->right;
				curr->right = curr->left;
				curr->left = NULL;
			}
			curr = curr->right;
		}
	}
};