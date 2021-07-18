/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

void PreOrder(TreeNode *root,int d,map<int,vector<int>> &mp){
    if(root == NULL){
        return;
    }
    mp[d].push_back(root->val);
    PreOrder(root->left,d+1,mp);
    PreOrder(root->right,d,mp);
}
vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int>> mp;
    
    int d = 0;
    PreOrder(A,d,mp);
    vector<int> res;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        // int n = res.size();
        res.insert(res.end(),it->second.begin(),it->second.end());
    }
    return res;
}
