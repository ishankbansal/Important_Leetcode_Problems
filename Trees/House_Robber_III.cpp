// Approach : As we can't rob consecutively so there can be two possible answer for every node that is rob this node and rob without this node,
//               if we want to take this node to our answer then we consider the without rob value of left and right subtree
//               if we don't want to take this node then we will consider the max of both left with and without, similarly for right too.

class maxAmount{
public:
	int with_roberry;
	int without_roberry;
	maxAmount(){
		without_roberry = 0;
		with_roberry = 0;
	}
};

class Solution {
    maxAmount dfs(TreeNode* root){
        if(root == NULL){
            maxAmount p;
            return p;
        }
        
        maxAmount left = dfs(root->left);
        maxAmount right = dfs(root->right);
        
        maxAmount ans;
        ans.with_roberry = left.without_roberry + right.without_roberry + root->val;
        ans.without_roberry = max(left.without_roberry, left.with_roberry) + max(right.without_roberry, right.with_roberry);
        return ans;    
    }
public:
    int rob(TreeNode* root) {
        maxAmount ans = dfs(root);
        return max(ans.with_roberry, ans.without_roberry);
    }
};