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
    private int size(ListNode curr) {
        int size = 0;
        while (curr != null) {
            size++;
            curr = curr.next;
        }
        return size;
    }
    public ListNode[] splitListToParts(ListNode head, int k) {
        // Calculate the size of the linked list
        int size = size(head);
        // Create an array to store the heads of the resulting linked list parts
        ListNode[] heads = new ListNode[k];
        ListNode curr = head;

        // Calculate the number of nodes to put in each part and the remaining nodes
        int group = size / k;
        int remaining = size % k;

        for (int i = 0; i < k; i++) {
            int put = group;
            // If there are remaining nodes, distribute them among the first parts
            if (remaining > 0) {
                put++;
                remaining--;
            }
            
            // If the current part is empty, set it to null
            if (curr == null) {
                heads[i] = null;
            } else {
                // Set the head of the current part to the current node
                heads[i] = curr;
                curr = curr.next;
                ListNode prev = heads[i];
                // Traverse the current part and update the pointers
                for (int j = 1; j < put; j++) {
                    prev.next = curr;
                    prev = prev.next;
                    curr = curr.next;
                }
                // Disconnect the current part from the rest of the list
                prev.next = null;
            }
        }
        // Return the array containing the heads of the linked list parts
        return heads;
    }
}