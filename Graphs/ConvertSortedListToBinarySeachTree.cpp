/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

TreeNode *solve(ListNode *A)
{
    if (A == NULL)
    {
        return NULL;
    }
    if (A->next == NULL)
    {
        TreeNode *node = new TreeNode(A->val);
        return node;
    }
    //reach mid
    //1_.2_.3_.4
    ListNode *slow = A, *fast = A;
    ListNode *prev = NULL, *post = NULL;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        post = slow->next;
        fast = fast->next->next;
    }
    TreeNode *node = new TreeNode(slow->val);
    prev->next = NULL;
    //assign node = mid
    node->left = solve(A);
    node->right = solve(post);
    //node->left = solve(left_list)
    //node->right = solve(right_list)
    return node;
}
TreeNode *Solution::sortedListToBST(ListNode *A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    TreeNode *ans = solve(A);
    return ans;
}
