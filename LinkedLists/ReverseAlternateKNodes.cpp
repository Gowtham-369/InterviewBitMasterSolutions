/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    ListNode *head = new ListNode(INT_MIN);
    head->next = A;
    
    ListNode *temp = A,*temp2 = head;
    int flag = 1;
    while(temp != NULL){
        int cnt = B;
        if(flag){
            //reverse
            ListNode *prev = NULL;
            ListNode *cur = temp;
            while(cnt>0 && cur != NULL){
                ListNode *temp2 = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp2;
                cnt -= 1;
            }
            temp->next = cur;
            temp2->next = prev;
            
            temp2 = prev;
            temp = cur;
        }
        else{
            ListNode *prev = NULL,*cur = temp;
            while(cnt>0 && cur != NULL){
                prev = cur;
                cur = cur->next;
                cnt -= 1;
            }
            temp2 = prev;
            temp = cur;
        }
        
        flag ^= 1;
        // cout<<"print List\n";
        // ListNode *t = A;
        // while(t != NULL){
        //     cout<<t->val<<" ";
        //     t = t->next;
        // }
        // cout<<"\n";
    }
    return head->next;
}
