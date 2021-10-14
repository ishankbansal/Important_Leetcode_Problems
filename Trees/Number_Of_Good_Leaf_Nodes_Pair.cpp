// Problem link -> https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
// Approach :-
// * At any node we have to calculate the distance of leaf node to its left Subtree and right Subtree
// * if the distace of sum left leaf node and right leaf node is less than equal to the given distance then we consider in our answer

class Solution{
	vector<int> help(TreeNode* root, int &ans, int distance){
		if(root == NULL){
			return {};
		}

		if(root->left == root->right){
			return {1};
		}

		vector<int> left = help(root->left, ans, distance); 
		vector<int> right = help(root->right, ans, distance); 

		for(int i = 0; i < left.size(); i++){
			for(int j = 0; j < right.size(); j++){
				if(left[i] + right[j] <= distance){
					ans++;
				}
			}
		}

		vector<int> res;

		for(int i = 0; i < left.size(); i++){
			res.push_back(left[i] + 1);
		}

		for(int i = 0; i < right.size(); i++){
			res.push_back(right[i] + 1);
		}

		return res;
	}
public:
	int countPairs(TreeNode* root, int distance){
		int ans = 0;
		help(root, ans, distance);
		return ans;
	}
};