

class Solution {
    int lengthOfLinkedList(ListNode* head) {
        int length = 0;
        while(head != NULL) {
            ++length;
            head = head->next;
        }
        return length;
    }
    public:
    ListNode* reverseKGroup(ListNode* &head, int k) {
        if(head == NULL||head->next == NULL) return head;

        int length = lengthOfLinkedList(head);

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        ListNode* cur;
        ListNode* nex;

        while(length >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            length -= k;
        }
        return dummyHead->next;
    }
};

// super hard question

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	Node* dummy = new Node(-1);
    dummy->next=head;
    
    Node* prev=dummy;
    Node* curr=dummy;
    Node* next=dummy;
    
    int count=0;
    while(curr->next){
        curr=curr->next;
        count++;
    }
    int j=0;
    while(count>0 && j<n){
        curr=prev->next;
        next=curr->next;
        int x=(b[j]<=count)? b[j]:count;
        if(x==0){
            j++;
            continue;
        }
        for(int i=1; i<x; i++){
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
            next=curr->next;
        }
        prev=curr;
        count-=b[j];
        j++;
    }
    return dummy->next;
}