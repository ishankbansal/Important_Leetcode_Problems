// Problem Link -> https://practice.geeksforgeeks.org/problems/largest-bst/1#
// Approach :-
// * Node > maximum of left Subtree
// * Node < minimum of right Subtree
// * left Subtree && Right Subtree should also a BST
// * If all these conditions are true than we can update our answer

class Info{
 public:
    int ans;
    int size;
    int max;
    int min;
    bool isBST;
    
    Info(){
        ans = 0;
        size = 0;
        max = INT_MIN;
        min = INT_MAX;
        isBST = true;
    }
};
class Solution{
    Info helper(Node* root){
        if(root == NULL){
            Info curr;
            return curr;
        }
        
        if(root->left == root->right){
            Info curr;
            curr.size = curr.ans = 1;
            curr.max = curr.min = root->data;
            return curr;
        }
        
        Info leftSub = helper(root->left);
        Info rightSub = helper(root->right);
        
        Info curr;
        curr.size = 1 + leftSub.size + rightSub.size;
        
        if(leftSub.isBST && rightSub.isBST && leftSub.max < root->data && rightSub.min > root->data){
            curr.min = min(root->data, min(leftSub.min, rightSub.min));
            curr.max = max(root->data, max(leftSub.max, rightSub.max));
            curr.ans = curr.size;
            return curr;
        }
        
        curr.ans = max(leftSub.ans, rightSub.ans);
        curr.isBST = false;
        return curr;
    }
    
    public:
    int largestBst(Node *root)
    {
    	return helper(root).ans;
    }
};
