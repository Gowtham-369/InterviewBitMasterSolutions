/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode *Solution::copyRandomList(RandomListNode *A)
{

    RandomListNode *dummy = new RandomListNode(0);
    RandomListNode *temp1 = A, *temp2 = dummy;
    while (temp1 != NULL)
    {
        temp2->label = temp1->label;
        temp2->random = temp1->random;
        RandomListNode *Next = temp1->next;
        temp1->next = temp2;
        temp1 = Next;
        if (temp1 != NULL)
        {
            temp2->next = new RandomListNode(0);
            temp2 = temp2->next;
        }
    }

    temp2 = dummy;
    while (temp2 != NULL)
    {
        if (temp2->random)
            temp2->random = temp2->random->random;
        temp2 = temp2->next;
    }
    return dummy;
}
