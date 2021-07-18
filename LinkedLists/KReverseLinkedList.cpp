/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode *dummy = new ListNode(INT_MIN);
    dummy->next = A;
    ListNode *temp2 = dummy;
    ListNode *temp = A;
    while(temp != NULL){
        int cnt = B;
        ListNode *prev = NULL,*cur=temp;
        while(cnt>0 && cur != NULL){
           ListNode *temp1 = cur->next;
           cur->next = prev;
           prev = cur;
           cur = temp1;
            cnt -= 1;
        }
        temp2->next = prev;
        temp2 = temp;
        temp = cur;
    }
    return dummy->next;
    
    
    
}
