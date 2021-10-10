// Problem link -> https://leetcode.com/problems/maximum-binary-tree/

// Approach - 1 : Brute Force O(N^2)
// * We will just find the max element in the given range and its index too
// * and make node and call recursilve to it left and right part

class Solution{
	int findMax(vector<int>& nums, int start, int end){
		int idx;
		int val = INT_MIN;
		for(int i = start; i <= end; i++){
			if(nums[i] > val){
				val = nums[i];
				idx = i;
			}
		}

		return idx;
	}

	TreeNode* construct(vector<int>& nums, int start, int end){
		if(start > end){
			return NULL;
		}

		int index = findMax(nums, start, end);
		TreeNode* node = new TreeNode(nums[index]);

		node->left = construct(nums, start, index - 1);
		node->right = construct(nums, index + 1, end);
		return node;
	}
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums){
		return construct(nums, 0, nums.size() - 1);
	}
};

// Approach - 2 : Using Stack O(N)
// * We will use stack and maintain a strictly decreasing order while traversing from left to right
// * Whenever we encounter a num which is greater than our top of the stack we will attach that top element to the left of current num do this till we empty the stack or get a greater number then num

class Solution{
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums){
		stack<TreeNode*> st;
		int n = nums.size();

		for(int i = 0; i < n; i++){
			TreeNode* node = new TreeNode(nums[i]);
			while(!st.empty() && st.top()->val < node->val){
				node->left = st.top();
				st.pop();
			}

			if(!st.empty()){
				st.top()->right = node;
			}

			st.push(node);
		}

		while(st.size() > 1){
			st.pop();
		}

		return st.top();
	}
}; 