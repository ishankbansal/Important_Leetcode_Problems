// Problem link -> https://leetcode.com/problems/recover-binary-search-tree/
// Approach - 1:
//* Use Morris Inorder Traversal
class Solution{
public:
	void recoverTree(TreeNode* root){
		TreeNode* curr = root, *prev = NULL, *a = NULL, *b = NULL;

		while(curr){
			TreeNode* leftNode = curr->left;
			if(!leftNode){
				if(prev && prev->val > curr->val){
					if(a == NULL){
						a = prev;
					}
					b = curr;
				}
				prev = curr;
				curr = curr->right;
			}
			else{
				while(!leftNode->right && leftNode->right != curr){
					leftNode = leftNode->right;
				}

				if(!leftNode->right){
					leftNode->right = curr;
					curr = curr->left;
				}
				else{
					leftNode->right = NULL;
					if(prev->val > curr->val){
						if(a == NULL){
							a = prev;
						}
						b = curr;
					}
					prev = curr;
					curr = curr->right;
				}
			}
		}

		swap(a->val, b->val);
	}
};