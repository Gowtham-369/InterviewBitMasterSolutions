/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void LevelOrder(TreeNode *root,vector<vector<int>> &ans){
    if(root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> v;
        int n = (int)q.size();
        while(n>0){
            TreeNode *node = q.front();
            q.pop();
            v.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
            n -= 1;
        }
        ans.push_back(v);
    }
}
vector<int> Solution::solve(TreeNode* A) {
    vector<vector<int>> ans;
    LevelOrder(A,ans);
    reverse(ans.begin(),ans.end());
    vector<int> res;
    for(auto vec:ans){
        res.insert(res.end(),vec.begin(),vec.end());
    }
    return res;
}
