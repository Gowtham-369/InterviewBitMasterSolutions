/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(int l,int r,vector<int> &A){
    if(l>r){
        return NULL;
    }
    int ind = max_element(A.begin+l,A.begin()+r+1)-A.begin();
    TreeNode *root = new TreeNode(A[ind]);
    root->left = solve(l,ind-1,A);
    root->right = solve(ind+1,r,A);
    return root;
    
}
TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    return solve(0,n-1,A)
}
