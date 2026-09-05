/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node *ptr=head;

        while(ptr!=NULL)
        {
            Node *tmp = new Node(ptr->val);
            tmp->next=ptr->next;
            ptr->next=tmp;
            ptr=tmp->next;
        }
        ptr=head;
        while(ptr)
        {
            if(ptr->random)
            ptr->next->random=ptr->random->next;
            ptr=ptr->next->next;
        }
        ptr=head;
        Node *ans=head->next;
        Node *res=head->next;
        while(ans->next)
        {
            ptr->next=ptr->next->next;
            ans->next=ans->next->next;
            ptr=ptr->next;
            ans=ans->next;
        }
        ptr->next=NULL;
        ans->next=NULL;
        return res;

    }
};
