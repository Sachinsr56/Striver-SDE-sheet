
// --------Easy to understand -----------

int length(Node* head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
int findIntersection(Node *first, Node *second)
{
    if(first==NULL && second==NULL)
        return -1;
    int len1=length(first),len2=length(second),d=0;
    Node* node1;Node* node2;
    if(len1>len2){
        d=len1-len2;
        node1=first;
        node2=second;
    }
    else{
        d=len2-len1;
        node1=second;
        node2=first;
    }
    while(d>0){
        node1=node1->next;
        d--;
    }
    while(node1 && node2){
        if(node1==node2)
            return node1->data;
        node1=node1->next;
        node2=node2->next;
    }
    return -1;
}

// -----------lightWeight-----------------

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *first=firstHead;
    Node *second=secondHead;
    while(first!=second){
        if(first==NULL)
            first=secondHead;
        else
            first=first->next;
        if(second==NULL)
            second=firstHead;
        else
            second=second->next;
    }if(first==NULL)
        return -1;
    else
        return first->data;
}