
LinkedListNode<int>* reverse(LinkedListNode<int>* head){
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    while(curr!=NULL){
        LinkedListNode<int>* tmp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=tmp;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(!head || !(head->next))
        return true;
    
    LinkedListNode<int>* slow=head;
    LinkedListNode<int>* fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    LinkedListNode<int>* head1=slow->next;
    slow->next=NULL;
    LinkedListNode<int>* mid=reverse(head1);
    LinkedListNode<int>* head2=head;
    while(mid && head2){
        if(head2->data!=mid->data)
        {
            return false;
        }
        head2=head2->next;
        mid=mid->next;
    }
    return true;
}