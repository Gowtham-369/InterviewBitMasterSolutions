/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
void Traversal(TreeNode *root,vector<int> &ans){
    if(root == NULL{
        return;
    }
    Traversal(root->left,ans);
    ans.push_back(root->val);
    Traversal(root->right,ans);
}
*/
void Inorder(TreeNode *root, vector<int> &ans)
{
    stack<TreeNode *> st;
    while (root != NULL)
    {
        st.push(root);
        root = root->left;
    }
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        ans.push_back(node->val); //inorderTraversal
        node = node->right;
        while (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
    }
}
vector<int> Solution::inorderTraversal(TreeNode *A)
{
    vector<int> ans;
    // Traversal(A,ans);
    Inorder(A, ans);
    return ans;
}
