/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void LevelOrder(TreeNode *root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        int n = q.size();
        vector<int> v;
        bool flag = false;
        while(n>0){
            TreeNode *node = q.front();
            q.pop();
            if(flag==false){
                v.push_back(node->val);
                flag = true;
            }
            if(node->right)
                q.push(node->right);
            if(node->left)
                q.push(node->left);
            n -= 1;
        }
        ans.insert(ans.end(),v.begin(),v.end());
    }
    
}
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    LevelOrder(A,ans);
    return ans;
}
