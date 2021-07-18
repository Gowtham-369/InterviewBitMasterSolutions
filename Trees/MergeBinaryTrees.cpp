/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void Merge(TreeNode *root1,TreeNode *root2,TreeNode *&root){
    if(root1 == NULL && root2 == NULL){
        root = NULL;
        return;
    }
    else if(root1 == NULL){
        root = root2;
    }
    else if(root2 == NULL){
        root = root1;
    }
    else{
        root = new TreeNode(root1->val+root2->val);
        Merge(root1->left,root2->left,root->left);
        Merge(root1->right,root2->right,root->right);
    }
}
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    TreeNode *root1 = A,*root2 = B;
    TreeNode *root;
    Merge(root1,root2,root);
    return root;
}