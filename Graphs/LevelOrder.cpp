/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::levelOrder(TreeNode *A)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        ans.push_back(res);
    }
    return ans;
}
