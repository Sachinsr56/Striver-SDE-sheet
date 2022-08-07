#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* a,Node *b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    Node* res;
    if(a->data < b->data){
        res=a;
        res->child=merge(a->child,b);
    }
    else{
        res=b;
        res->child=merge(a,b->child);
    }
    res->next=NULL;
    return res;
}

Node* flattenLinkedList(Node* head) 
{
    if(!head || !(head->next))
        return head;
    head->next=flattenLinkedList(head->next);
    head=merge(head,head->next);
    return head;
}
