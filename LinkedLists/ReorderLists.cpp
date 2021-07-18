/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
    ListNode *temp1=A,*temp2=A->next;
    while(temp2!=NULL && temp2->next != NULL){
        ListNode *prev=temp1,*cur = temp2;
        while(cur->next != NULL){
            prev = cur;
            cur = cur->next;
        }
        temp1->next = cur;//inserted last ele
        cur->next = temp2;
        prev->next = NULL;//deleted last ele
        temp1 = temp2;
        temp2 = temp2->next;
    }
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
ListNode* Solution::reorderList(ListNode* A) {
    
    if(A == NULL || A->next ==NULL){
        return A;
    }
    ListNode *slow = A,*fast = A;
    //1 2 3 4 5 
    // mid at 3
    //1 2 3 4
    //mid at 3
    ListNode *prev = NULL;
    while(fast!=NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;//terminate first list
    slow = reverse(slow);
    ListNode *temp1 = A,*temp2 = slow;
    ListNode *head = new ListNode(INT_MIN);
    head->next = A;
    ListNode *temp = head;
    while(temp1 != NULL){
        temp->next = temp1;
        temp1 = temp1->next;
        temp = temp->next;
        temp->next = temp2;
        temp2 = temp2->next;
        temp = temp->next;
    }
    return head->next;
}
