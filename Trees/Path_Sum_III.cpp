// Problem Link -> https://leetcode.com/problems/path-sum-iii/
// Approach :- (Prefix Sum + DFS)
// We will Store the sum and whenever we get the [prefixsum - target] present in our DS we add it to our answer

class Solution {
public:
    
    void find(TreeNode* root, unordered_map<int, int> &vis, int prefixsum, int targetSum, int &ans){
        prefixsum += root->val;
        ans += vis[prefixsum - targetSum];
        vis[prefixsum]++;
        if(root->left){
            find(root->left, vis, prefixsum, targetSum, ans);
        }
        if(root->right){
            find(root->right, vis, prefixsum, targetSum, ans);
        }
        // Bactracking Step
        vis[prefixsum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        if(root == NULL){
            return 0;
        }
        unordered_map<int, int> m;
        m[0] = 1;
        find(root, m, 0, targetSum, ans);
        return ans;
    }
};