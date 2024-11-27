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
    public int count(ListNode head){
        int cnt=0;
        ListNode temp = head;
        while(temp!=null){
            temp=temp.next;
            cnt++;
        }
        return cnt;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode t = head;
        int c = count(head);
        if (c == n) {
            return head.next;
        }
        while(t != null){
            c--;
            if(c==n){
                t.next=t.next.next;
            }
            t=t.next;
        }
        return head;
    }
}