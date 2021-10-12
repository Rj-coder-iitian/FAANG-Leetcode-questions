//23. Merge k Sorted Lists
//https://leetcode.com/problems/merge-k-sorted-lists/
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.


public class mergeKsortedLists {
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

    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0)
            return null;

        ListNode refList = null;
        for (int i = 0; i < lists.length; i++) {
            refList = merge2Lists(refList, lists[i]);
        }
        return refList;
    }

    public ListNode merge2Lists(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null)
            return l1 != null ? l1 : l2;

        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;
        ListNode c1 = l1;
        ListNode c2 = l2;

        while (c1 != null && c2 != null) {
            if (c1.val >= c2.val) {
                prev.next = c2;
                c2 = c2.next;
            } else {
                prev.next = c1;
                c1 = c1.next;
            }
            prev = prev.next;
        }
        if (c1 != null || c2 != null)
            prev.next = c1 != null ? c1 : c2;

        return dummy.next;
    }
}
