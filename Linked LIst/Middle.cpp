#include <bits/stdc++.h> 

Node *findMiddle(Node *head) {
    Node*  slow=head;
    Node* fast=head->next;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->next;
}
