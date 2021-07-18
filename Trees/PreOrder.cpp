/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void PreOrder(TreeNode *root,vector<int> &ans){
    stack<TreeNode*> st;
    TreeNode *node = root;
    while(node != NULL){
        ans.push_back(node->val);
        st.push(node);
        node = node->left;
    }
    while(!st.empty()){
        node = st.top();
        st.pop();
        node = node->right;
        while(node != NULL){
            ans.push_back(node->val);
            st.push(node);
            node = node->left;
        }
    }
    
}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    PreOrder(A,ans);
    return ans;
}
