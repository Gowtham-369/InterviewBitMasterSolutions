/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* PostOrder(TreeNode *root){
    if(root == NULL){
        return root;
    }
    root->left = PostOrder(root->left);
    root->right = PostOrder(root->right);
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
TreeNode* Solution::invertTree(TreeNode* A) {
    return PostOrder(A);
}
