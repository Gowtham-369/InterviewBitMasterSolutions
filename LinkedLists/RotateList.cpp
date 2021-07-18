/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    // ListNode *dummy = new ListNode(INT_MIN);
    ListNode *temp = A;
    int n = 0;
    while(temp != NULL){
        temp = temp->next;
        n += 1;
    }
    int k = B%n;
    int m = n-k;
    temp = A;
    ListNode *prev=A;
    while(m>0 && temp != NULL){
        prev = temp;
        temp = temp->next;
        m -= 1;
    }
    prev->next = NULL;//terminate this list
    ListNode *head = temp;
    prev = temp;
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL){
        return A;
    }
    else{
        prev->next = A;
        return head;
    }
    
}
