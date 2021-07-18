/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode *root,int B,int sum,vector<int> ans,vector<vector<int>> &res){
    if(root == NULL){
        return;
    }
    ans.push_back(root->val);
    sum += root->val;
    if(root->left == NULL and root->right == NULL and sum == B){
        res.push_back(ans);
        return;
    }
    solve(root->left,B,sum,ans,res);
    solve(root->right,B,sum,ans,res);
    // ans.pop_back();
    // sum -= root->val;
    
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> ans;
    int sum = 0;
    solve(A,B,sum,ans,res);
    return res;
}
