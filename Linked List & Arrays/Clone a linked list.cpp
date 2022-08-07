#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*>m;
    LinkedListNode<int>* temp=head;
    
    while(temp){
        LinkedListNode<int>* newNode=new LinkedListNode<int>(temp->data);
        m[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while(temp){
        LinkedListNode<int>* newNode=m[temp];
        newNode->next=m[temp->next];
        newNode->random=m[temp->random];
        temp=temp->next;
    }
    return m[head];
}
