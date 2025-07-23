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
    public ListNode middleNode(ListNode head) {
        ListNode curr = head;
        int cnt=0;
        while(head!=null){
            head=head.next;
            cnt++;
        }
        for(int i=0;i<cnt/2;i++) curr=curr.next;
        return curr;
    }
}