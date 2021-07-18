/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void Traversal(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    Traversal(root->left, ans);
    Traversal(root->right, ans);
    ans.push_back(root->val);
}

vector<int> Solution::postorderTraversal(TreeNode *A)
{
    vector<int> ans;
    // Traversal(A,ans);
    // PostOrder(A,ans);
    if (A == NULL)
        return ans;
    stack<TreeNode *> s;
    s.push(A);

    while (s.size())
    {
        TreeNode *prev = s.top();
        ans.push_back(s.top()->val);
        s.pop();
        if (prev->left)
        {
            s.push(prev->left);
        }
        if (prev->right)
        {
            s.push(prev->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}