// 92. Reverse Linked List II

// Given the head of a singly linked list and two integers left and right where 
// left <= right, reverse the nodes of the list from position left to position right, 
// and return the reversed list.


public class reverseLLfrom_mton {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode forw = curr.next; // backup

            curr.next = prev; // link

            prev = curr; // move
            curr = forw;
        }

        return prev;
    }

    public ListNode reverseListRec(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode nextNode = head.next;
        head.next = null;
        ListNode rl = reverseListRec(nextNode);
        nextNode.next = head;

        return rl;
    }
}
