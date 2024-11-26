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
    public int countnode(ListNode head){
        int cnt=0;
        ListNode temp = head;
        while(temp!=null){
            cnt++;
            temp=temp.next;
        }
        return cnt;
    }
    public ListNode middleNode(ListNode head) {
        int middle = countnode(head)/2;
        for(int i=0;i<middle;i++){
            head=head.next;
        }
        return head;
    }
}