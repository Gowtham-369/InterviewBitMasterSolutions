/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void Flatten(TreeNode *&root){
    if(root == NULL){
        return;
    }
    Flatten(root->left);
    Flatten(root->right);
    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = NULL;
    TreeNode *temp2 = root;
    while(temp2->right != NULL){
        temp2 = temp2->right;
    }
    temp2->right = temp;
}

TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    Flatten(A);
    return A;
    
}
