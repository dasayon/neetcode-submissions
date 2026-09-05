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
        
        ListNode *curr,*prev,*end,*dummy=head;
        int i=1,k=0;
        while(dummy)
            {
                k++;
                dummy=dummy->next;

            }
        if(k==n)
            return head->next;
        end=head;
        while(i<=n&&end)
            {
                end=end->next;i++;
            }

        curr=head,prev=NULL;

        while(end!=NULL)
        {   prev=curr;
            curr=curr->next;
            end=end->next;
        }
        if(prev&&curr)
        prev->next=curr->next;
        prev=NULL;
        return head;
    }
};
