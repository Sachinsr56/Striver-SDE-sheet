#include <bits/stdc++.h> 

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head==NULL || K==0)
        return head;
    LinkedListNode<int>* dummy = new LinkedListNode<int>(-1);
    LinkedListNode<int>* slow=dummy;
    LinkedListNode<int>* fast=dummy;
    dummy->next=head;
    while(K--){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return dummy->next;
}