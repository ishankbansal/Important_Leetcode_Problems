//Problem link -> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Approach - 1 :- (RECURSIVE)
//* Postorder Traversal
//* whenever encounter a any of the given nodes we return
//* Three Posibilites :-
// i)  we found one node from left subtree and another node from right subtree of the curr node in that case we return "curr node"
// ii) we found the node from left subtree then return that left node
// iii) we found the node from right subtree then return that right node

class Solution{
public:
	TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
		if(root == NULL){
			return NULL;
		}

		if(root == p || root == q){
			return root;
		}

		TreeNode* left = LCA(root->left, p, q);
		TreeNode* right = LCA(root->right, p, q);

		if(left && right){
			return root;
		}

		if(left){
			return left;
		}

		return right;
	}
};