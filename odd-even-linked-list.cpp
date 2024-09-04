/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
         ListNode oddHead = new ListNode(0);
        ListNode evenHead = new ListNode(0);
        ListNode odd = oddHead;
        ListNode even = evenHead;

        ListNode current = head;

        int i = 1;
        while( current != null ){
            if( i%2 == 0 ){
                even.next = current;
                even = even.next;
            }
            else{
                odd.next = current;
                odd = odd.next;
            }
            current = current.next;
            i++;
        }

        even.next = null;
        odd.next = evenHead.next;

        return oddHead.next;
    }
}