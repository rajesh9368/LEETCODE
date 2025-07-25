/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        HashSet<ListNode> st = new HashSet<>();
        if(head==null|| head.next==null) return false;
        ListNode temp = head;
        while(temp!=null){
            if(st.contains(temp)) return true;
            st.add(temp);
            temp = temp.next;
        }
        return false;
    }
}