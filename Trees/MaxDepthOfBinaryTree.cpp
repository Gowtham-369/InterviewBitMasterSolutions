/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int HeightOfTree(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int l_h = HeightOfTree(root->left);
    int r_h = HeightOfTree(root->right);
    return max(l_h,r_h)+1;
}
int Solution::maxDepth(TreeNode* A) {
    return HeightOfTree(A);
}