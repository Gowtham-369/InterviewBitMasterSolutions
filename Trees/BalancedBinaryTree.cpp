/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int PostOrder(TreeNode *root, int &valid)
{
    if (root == NULL)
    {
        return 0;
    }
    int l_h = PostOrder(root->left, valid);
    int r_h = PostOrder(root->right, valid);
    if (abs(r_h - l_h) > 1)
    {
        valid = 0;
    }
    return max(l_h, r_h) + 1;
}
int Solution::isBalanced(TreeNode *A)
{
    int valid = 1;
    int height = PostOrder(A, valid);
}
