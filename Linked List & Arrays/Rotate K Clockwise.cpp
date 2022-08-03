// ----------------just like array--------------

int length(Node* head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
Node *rotate(Node *head, int k) {
    if(!head)
        return head;
    
    int n=length(head);
    k=k%n;
    k=n-k;
    Node* ans=new Node(-1);
    Node* ansHead=ans;
    int d=k;
    Node* node=head;
    while(d--){
        node=node->next;
    }
    while(node){
        ans->next=new Node(node->data);
        ans=ans->next;
        node=node->next;
    }
    for(int i=1; i<=k; i++){
        ans->next=new Node(head->data);
        ans=ans->next;
        head=head->next;
    }
    return ansHead->next;
}