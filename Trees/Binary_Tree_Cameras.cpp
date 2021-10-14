// Problem link -> https://leetcode.com/problems/binary-tree-cameras/
// Approach :-
// * If we are at a node, and one of the child doesn't covered under camera then we have to give camera to the curr node
// * if both the child covered under the camera and even one of them have camera then we don't need to give camera to curr node
// * If both the child covered under the camera but none of them have camera then we request a camera from our parent node

// CORNER CASE -> let say left child and right child of ROOT node are covered under the  camera but none of them have camera then we have to 
//                give camera to the root node because ROOT doesn't have any parent

/* 
 0 -> node doesn't cover under camera
 1 -> node have camera
 2 -> node covered under camera but doesn't have camera
*/

class Solution{
	int dfs(TreeNode* root, int &ans){
		if(root == NULL){
			return 2;
		}

		int left = dfs(root->left, ans);
		int right = dfs(root->right, ans);

		if(left == 0 || right == 0){
			ans++;
			return 1;
		}

		if(left == 1 || right == 1){
			return 2;
		}

		return 0;
	}
public:
	int minCameraCover(TreeNode* root){
		int ans = 0;
		int val = dfs(root, ans);
		if(val == 0){
			ans++;
		}
		return ans;
	}
};
