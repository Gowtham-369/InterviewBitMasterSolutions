/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root,int height,int &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans = min(ans,height);
        return;
    }
    solve(root->left,height+1,ans);
    solve(root->right,height+1,ans);
}
int Solution::minDepth(TreeNode* A) {
    int height = 1;
    int ans = INT_MAX;
    solve(A,height,ans);
    if(ans == INT_MAX){
        ans = 0;
    }
    return ans;
}
