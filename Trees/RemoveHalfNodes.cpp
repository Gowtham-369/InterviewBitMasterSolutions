/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* PostOrder(TreeNode* root){
    if(root == NULL){
        return root;
    }
    
    root->left = PostOrder(root->left);//subtrees are being changed
    root->right = PostOrder(root->right);
    int f1 = (root->left==NULL?1:0);
    int f2 = (root->right==NULL?1:0);
    if(f1^f2){
        if(f1==1){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return root;
}
TreeNode* Solution::solve(TreeNode* A) {
    return PostOrder(A);
}
