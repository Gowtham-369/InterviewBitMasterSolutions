/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::solve(ListNode *A)
{
    int n_zeros = 0, n_ones = 0;
    ListNode *temp = A;
    while (temp != NULL)
    {
        if (temp->val == 0)
        {
            n_zeros += 1;
        }
        else
        {
            n_ones += 1;
        }
        temp = temp->next;
    }
    temp = A;
    while (temp != nullptr)
    {
        if (n_zeros > 0)
        {
            temp->val = 0;
            n_zeros -= 1;
        }
        else
        {
            temp->val = 1;
            // n_ones -= 1;
        }
        temp = temp->next;
    }
    return A;
}

