/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *curr,*dummy=head;
        int i=1,k=0;
        while(dummy)
            {
                k++;
                dummy=dummy->next;

            }
        if(k==n)
            return head->next;
        dummy=head;
        while(i<=n&&dummy)
            {
                dummy=dummy->next;i++;
            }

        curr=head;

        while(dummy->next!=NULL)
        {   //prev=curr;
            curr=curr->next;
            dummy=dummy->next;
        }
        if(curr&&curr->next)
        curr->next=curr->next->next;
        return head;
    }
};
