/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::partition(ListNode *A, int x)
{
    ListNode *head1 = new ListNode(INT_MIN);
    ListNode *head2 = new ListNode(INT_MIN);
    ListNode *temp = A, *temp1 = head1, *temp2 = head2;
    while (temp != NULL)
    {
        if (temp->val < x)
        {
            temp1->next = temp;
            temp1 = temp1->next;
        }
        else
        {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    temp2->next = NULL;        //terminate second list
    temp1->next = head2->next; //connect 1st to 2nd
    return head1->next;
}