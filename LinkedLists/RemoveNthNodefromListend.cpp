/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode *dummy = new ListNode(INT_MIN);
    ListNode *temp = dummy;
    temp->next = A;
    int n = 0;
    ListNode *temp1 = A;
    while(temp1 != NULL){
        n += 1;
        temp1 = temp1->next;
    }
    int from_start = n-B+1;
    //remove from_start
    if(from_start <= 0){
        from_start = 1;
    }
    from_start -= 1;
    ListNode *prev = dummy,*cur = A;
    while(from_start>0 && cur != NULL){
        prev = cur;
        cur = cur->next;
        from_start -= 1;
    }
    if(cur != NULL)
        prev->next = cur->next;
    return dummy->next;
}
