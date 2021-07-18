/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
    ListNode *temp1=A;
    //Bubble sort
    while(temp1 != NULL){
        ListNode *temp2=temp1->next;
        int cur_val = temp1->val;
        while(temp2 != NULL){
            if(temp2->val < cur_val){
                temp1->val = temp2->val;
                temp2->val = cur_val;
                cur_val = temp1->val;
            }
            temp2 = temp2->next;
        }
        //temp1->val is least of all
        temp1 = temp1->next;
    }
    return A;
*/
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *head = new ListNode(INT_MIN);
    head->next = A;
    
    ListNode *prev = head;
    ListNode *cur = A;
    while(cur != NULL){
        while(cur!=NULL && prev->val<=cur->val){
            prev = cur;
            cur = cur->next;
        }
        //prev->val > cur->val
        ListNode *temp = head;
        while(cur->val >= temp->next->val){
            temp = temp->next;
        }
        prev->next = cur->next;
        cur->next = temp->next;//placing at correct position
        temp->next = cur;
        cur = prev->next;
    }
    return head->next;//A
}
/*
for(int i=1; i<n; i++){
    while(i<n && A[i]<=A[i-1]){
        i += 1;
    }
    // ipos
    int j= i-1;
    while(j >= 0 and A[j] >= A[i]){
        A[j+1] = A[j];
        j -= 1;
    }
    A[j] = A[i];
    
}
*/
