/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *head = new ListNode(INT_MIN);
    head->next = A;
    ListNode *temp1 = head;
    int m = B-1;
    while(m>0){
        temp1 = temp1->next;
        m -= 1;
    }
    ListNode *temp2 = temp1->next;
    
    int cnt = C-B+1;//simulate and get this
    //reverse till cnt
    ListNode *prev=NULL,*cur = temp2;
    while(cnt>0 && cur != NULL){
        ListNode *temp3 = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp3;
        cnt -= 1;
    }
    //reversely connected
    temp2->next = cur;
    temp1->next = prev;
    return head->next;
}
