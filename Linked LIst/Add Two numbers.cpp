#include <bits/stdc++.h> 

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    int carry=0;
    while(head1 || head2 || carry){
        int sum=0;
        if(head1){
            sum+=head1->data;
            head1=head1->next;
        }
        if(head2){
            sum+=head2->data;
            head2=head2->next;
        }
        sum+=carry;
        carry=sum/10;
        temp->next=new Node(sum%10);
        temp=temp->next;
    }
    return dummy->next;
}