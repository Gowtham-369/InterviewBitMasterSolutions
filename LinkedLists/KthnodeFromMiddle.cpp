/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode *A, int B)
{
    int n = 0;
    ListNode *temp = A;
    while (temp != NULL)
    {
        n += 1;
        temp = temp->next;
    }
    int mid = n / 2 + 1;
    int ind = (n - mid + 1) + B; //from last
    if (ind > n)
    {
        return -1;
    }
    int from_start = n - ind + 1;
    from_start -= 1; //0 indexing
    temp = A;
    while (from_start > 0)
    {
        temp = temp->next;
        from_start -= 1;
    }
    return temp->val;
}
