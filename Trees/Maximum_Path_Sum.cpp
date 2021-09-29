// Problem Link -> https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Approach :-
// At any node we have four choices
// 1. We can take only node
// 2. We can take node + it's left subtree
// 3. We can take node + it's right subtree
// 4. We can take node + left subtree + right subtree
// Our res will be the maximum of all of these

class Solution {
    int helper(TreeNode* root, int &res){
        if(root == NULL){
            return 0;
        }
        
        int leftSum = helper(root->left, res);
        int rightSum = helper(root->right, res);
        
        int temp = max(max(leftSum, rightSum) + root->val, root->val);
        int ans = max(temp, leftSum + rightSum + root->val);
        res = max(res, ans);
        
        return temp;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
};