class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int len=0;
		//count the length of the linked list
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
		//Now traversing from start and till count is not equal to len-n+1(for node from the end) them
		//simply just changes the refrence of nodes
        int count=1;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(count<len-n+1){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(prev!=NULL){
             prev->next=curr->next;
        }else{
             head=curr->next;
            delete curr;
        }
        return head;
       
    }
};
