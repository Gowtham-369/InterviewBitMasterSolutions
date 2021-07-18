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
    int mid = l+(r-l)/2;
    TreeNode *root = new TreeeNode(A[mid]);
    root->left = solve(l,mid-1,A);
    root->right = solve(mid+1,r,A);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    return solve(0,n-1,A);
}
