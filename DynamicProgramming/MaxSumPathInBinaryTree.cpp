/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = INT_MIN;
int solve(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int l_sum = solve(root->left);
    int r_sum = solve(root->right);
    int mid_sum = root->val;
    
    int return_value =  max(mid_sum,max(mid_sum+l_sum,mid_sum+r_sum));
    ans = max(ans,max(return_value,mid_sum+l_sum+r_sum));
    return return_value;
}
int Solution::maxPathSum(TreeNode* A) {
    ans = INT_MIN;
    int res = solve(A);
    return ans;
}
