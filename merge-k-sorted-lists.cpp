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
    public ListNode Merge(ListNode n1, ListNode n2){
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        while(n1!=null && n2!=null){
            if(n1.val <n2.val){
                curr.next = n1;
                n1 = n1.next;
            }else{
                curr.next = n2;
                n2 = n2.next;
            }
            curr = curr.next;
        }

        if(n1!=null){
            curr.next = n1;
        }
        if(n2!=null){
            curr.next = n2;
        }

        return dummy.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0 ){
            return null;
        }
        if(lists.length == 1){
            return lists[0];
        }
        ListNode merge = Merge(lists[0], lists[1]);
        for(int i =2; i<lists.length; i++){
            merge = Merge(merge,lists[i]);
        }
        return merge;
    }
}