// Problem link -> https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Approach - 1
// * First We will maintain map to store the parent of every node by which we can go to kth node from target through parent of target
// * After this we will run a BFS from target till we reach the kth level and just a slight variation in BFS 

class Solution{
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        vector<int> ans;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        q.push(target);
        visited[target] = true;
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            if(level == k){
                break;
            }
            level++;

            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

// Approach - 2
// * Using Recursion whenever I encounter target, I will store all the nodes at kth level from target which are below the target
// * Now we will return back to target's parent and now calculate the nodes at kth level


class Solution{

    void kthLevel(TreeNode* root, vector<int> &ans, int k){
        if(root == NULL || k < 0){
            return;
        }

        if(k == 0){
            ans.push_back(root->val);
        }

        kthLevel(root->left, ans, k - 1);
        kthLevel(root->right, ans, k - 1);
    }

    int AtDistancek(TreeNode* root, TreeNode* target, int k, vector<int>& ans){
        if(root == NULL){
            return -1;
        }

        if(root == target){
            kthLevel(root, ans, k);
            return 0;
        }

        int left = AtDistancek(root->left, target, k, ans);

        if(left != -1){
            if(left + 1 == k){
                ans.push_back(root->val);
            }
            else{
                kthLevel(root->right, ans, k - 2 - left);
            }
            return left + 1;
        }

        int right = AtDistancek(root->right, target, k, ans);

        if(right != -1){
            if(right + 1 == k){
                ans.push_back(root->val);
            }
            else{
                kthLevel(root->left, ans, k - 2 - right);
            }
            return right + 1;
        }

        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        vector<int> ans;
        AtDistancek(root, target, k, ans);
        return ans;
    }
};