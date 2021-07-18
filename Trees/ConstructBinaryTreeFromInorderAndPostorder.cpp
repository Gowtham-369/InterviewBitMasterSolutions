/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(int in_start,int in_end,vector<int> &in, int post_start,int post_end,vector<int> &post){
    if(post_start>post_end or in_start>in_end){
        return NULL;
    }
    int root_value = post[post_end];
    TreeNode *root = new TreeNode(root_value);
    int found_at = find(in.begin()+in_start,in.begin()+in_end+1,root_value)-in.begin();
    int len = found_at-in_start;
    root->left = solve(in_start,found_at-1,in,post_start,post_start+len-1,post);
    root->right = solve(found_at+1,in_end,in,post_start+len,post_end-1,post);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    return solve(0,n-1,A,0,n-1,B);
}
/*
TreeNode* solve(int pre_start,int pre_end,vector<int> &pre, int in_start,int in_end,vector<int> &in){
    if(pre_start>pre_end or in_start>in_end){
        return NULL;
    }
    int root_value = pre[pre_start];
    TreeNode *root = new TreeNode(root_value);
    int found_at = find(in.begin()+in_start,in.begin()+in_end+1,root_value)-in.begin();
    int len = found_at-in_start;
    root->left = solve(pre_start+1,pre_start+len,pre,in_start,found_at-1,in);
    root->right = solve(pre_start+len+1,pre_end,pre,found_at+1,in_end,in);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    return solve(0,n-1,A,0,n-1,B);
}
*/