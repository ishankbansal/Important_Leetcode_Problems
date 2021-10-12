// Problem link -> https://leetcode.com/problems/maximum-width-of-binary-tree/
// Approach:-
// * if a node is the kth node in a binary tree then left child will be (2 * k) and right child will be (2 * k + 1) [CONSIDERING FULL BINARY TREE]
// * so, to find max width we will calculate the first node and last node of every level and there difference + 1 will give us width of that level

#define ll unsigned long long

class Solution{
public:
	int widthOfBinaryTree(TreeNode* root){

		queue<pair<TreeNode*, ll> > q;
		q.push(make_pair(root, 1));
		ll ans = 1;

		while(!q.empty()){
			ll l = q.front().second, r;
			ll n = q.size();
			for(int i = 0; i < n; i++){
				TreeNode* curr = q.front().first;
				r = q.front().second;
				q.pop();

				if(curr->left){
					q.push(make_pair(curr->left, 2 * r));
				}
				if(curr->right){
					q.push(make_pair(curr->right, 2 * r + 1));
				}
			}
			ans = max(ans, r - l + 1);
		}

		return ans;
	}
};  