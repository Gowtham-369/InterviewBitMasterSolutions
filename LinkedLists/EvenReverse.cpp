/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverse(ListNode *head){
    ListNode *prev = NULL,*cur = head;
    while(cur != NULL){
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
} 
ListNode* Solution::solve(ListNode* A) {
    if(A == NULL or A->next == NULL or A->next->next == NULL){
        return A;
    }
    ListNode *head1 = A,*head2 = A->next;
    ListNode *temp1 = A,*temp2 = A->next;
    while(temp2 != NULL && temp2->next != NULL){
        ListNode *temp = temp2->next;
        temp1->next = temp;
        temp2->next = temp->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = NULL;//terminate first list
    head2 = reverse(head2);
    ListNode *dummy = new ListNode(INT_MIN);
    temp1 = head1,temp2 = head2;
    ListNode *temp = dummy;
    while(temp2 != NULL){
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = temp1;
    return dummy->next;
}
