/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode *head){
    ListNode *prev=NULL,*cur=head;
    while(cur != NULL){
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {
    ListNode *slow=A,*fast = A;
    ListNode *prev = A;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    ListNode *temp2 = reverse(slow);
    ListNode *temp1 = A;
    while(temp1 != NULL){
        if(temp1->val != temp2->val){
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}
