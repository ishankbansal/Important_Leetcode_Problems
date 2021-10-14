// Problem Link -> https://leetcode.com/problems/binary-tree-coloring-game/
// Approach :-
// * If we want to win this coloring game we have three options :-
//    i. We cover (or block) the whole left subtree of the red colored node 
//    ii. We cover (or block) the whole right subtree of the red colored node 
//    iii. We cover (or block) the parent of the red colored node 
// * From any of these possibilities if we are able to color more than n / 2 nodes from blue, then we can win

class Solution{
	int count(TreeNode* root, int &left_count, int &right_count, int x){
		if(root == NULL){
			return 0;
		}

		int l = count(root->left, left_count, right_count, x);
		int r = count(root->right, left_count, right_count, x);
		if(root->val == x){
			left_count = l;
			right_count = r;
		}
		return l + r + 1;
	}
public:
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		int left_count = 0;
		int right_count = 0;
        count(root, left_count, right_count, x);
		return max(max(left_count, right_count), n - left_count - right_count - 1) > n / 2;
	}
};