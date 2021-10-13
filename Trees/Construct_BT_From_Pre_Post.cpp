// Problem link -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
// Approach :-
// * Using Preorder to make node
// * Using Postorder to make decision that the node we choosen in preorder what it's left Subtree and right subtree

class Solution{
	TreeNode* build(vector<int>& preorder, int preS, int preE, vector<int>& postorder, int postS, int postE){
		if(preS > preE){
			return NULL;
		}
		TreeNode* root = new TreeNode(preorder[preS]);
		if(preS == preE){
			return root;
		}
		int idx = postS;
		while(postorder[idx] != preorder[preS + 1]){
			idx++;
		}

		int len = idx - postS + 1;
		root->left = build(preorder, preS + 1, preS + len, postorder, postS, idx);
		root->right = build(preorder, preS + len + 1, preE, postorder, idx + 1, posE - 1);
		return root;
	}
public:
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder){
		int n = preorder.size();
		return build(preorder, 0, n - 1, postorder, 0, n - 1);
	}
};
