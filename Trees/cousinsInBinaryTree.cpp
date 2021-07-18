/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void LevelOrder(TreeNode *root,int B,vector<int> &ans){
    if(root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(not q.empty()){
        int found = 0;
        int n = q.size();
        vector<TreeNode*> v;
        while(n>0){
            TreeNode *node = q.front();
            q.pop();
            v.push_back(node);
            if(node->left){
                if(node->left->val == B){
                    found = 1;
                    v.pop_back();
                }
                else{
                    q.push(node->left);
                }
            }
            if(node->right){
                if(node->right->val == B){
                    found = 1;
                    v.pop_back();
                }
                else{
                    q.push(node->right);
                }
            }
            n -= 1;
        }
        if(found){
            for(auto node:v){
                if(node->left){
                    ans.push_back(node->left->val);
                }
                if(node->right){
                    ans.push_back(node->right->val);
                }
            }
            return;
        }
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    LevelOrder(A,B,ans);
    return ans;
}
