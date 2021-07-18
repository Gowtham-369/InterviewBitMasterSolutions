ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *dummy = new ListNode(INT_MIN);
    //never use head node directly 
    ListNode *temp1 = dummy;
    ListNode *temp2 = A,*temp3 = B;
    while(temp2 != NULL && temp3 != NULL){
        if(temp2->val <= temp3->val){
            temp1->next = temp2;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        else{
            temp1->next = temp3;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
    }
    if(temp2 == NULL){
        temp1->next = temp3;
    }
    if(temp3 == NULL){
        temp1->next = temp2;
    }
    //eensure terminate lists by NULL
    return dummy->next;
}