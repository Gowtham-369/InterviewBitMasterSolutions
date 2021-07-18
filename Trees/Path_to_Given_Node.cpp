/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void Traversal(TreeNode *root,int B,vector<int> &res,bool &found){
    if(root == NULL || found){
        return;
    }
    res.push_back(root->val);
    if(root->val == B){
        found = true;
        return;
    }
    Traversal(root->left,B,res,found);
    Traversal(root->right,B,res,found);
    if(!found){
        res.pop_back();
    }
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    bool found = false;
    Traversal(A,B,res,found);
    return res;
}
