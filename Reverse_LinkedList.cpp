class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev= NULL;
        ListNode* next;
        while(current){
            next=current->next;
            current->next=prev;
            prev= current;
            current=next;
        }
        head = prev;
        return head;
        
    }
};
