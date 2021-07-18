/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode *root,int B,int sum,int &found){
    if(root == nullptr || found == 1){
        return;
    }
    sum += root->val;
    if(root->left == NULL && root->right == NULL){
        if(sum == B){
            found = 1;
        }
        return;
    }
    solve(root->left,B,sum,found);
    solve(root->right,B,sum,found);
}
int Solution::hasPathSum(TreeNode* A, int B) {
    int sum = 0;
    int found = 0;
    solve(A,B,sum,found);
    return found;
}