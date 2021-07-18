/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *dummy = new ListNode(INT_MIN);
    ListNode *temp3 = dummy;
    ListNode *temp = A;
    while(temp != NULL){
        ListNode *temp2 = temp->next;
        int cur = temp->val;
        int cnt = 1;
        while(temp2 != NULL && temp2->val == cur){
            cnt += 1;
            temp2 = temp2->next;
        }
        if(cnt == 1){
            temp3->next = temp;
            temp3 = temp3->next;
        }
        temp = temp2;
        
    }
    temp3->next = NULL;//treminate last link
    return dummy->next;
}
