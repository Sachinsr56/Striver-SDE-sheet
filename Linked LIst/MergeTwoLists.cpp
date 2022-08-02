
// --------- using recursion ------------------

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first)
        return second;
    else if(!second)
        return first;
    Node<int>* result;
    if(first->data<=second->data){
        result=first;
        result->next=sortTwoLists(first->next,second);
    }
    else{
        result=second;
        result->next=sortTwoLists(first,second->next);
    }
    return result;
}

// ------------------using dummy------------


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* ans = new Node<int>(-1);
    Node<int>* ansHead = ans;
    while(first && second){
        if(first->data <= second->data){
            ansHead->next=first;
            ansHead=ansHead->next;
            first=first->next;
        }
        else{
            ansHead->next=second;
            ansHead=ansHead->next;
            second=second->next;
        }
    }
    while(first){
        ansHead->next=first;
        ansHead=ansHead->next;
        first=first->next;
    }
    while(second){
        ansHead->next=second;
        ansHead=ansHead->next;
        second=second->next;
    }
    return ans->next;
}

