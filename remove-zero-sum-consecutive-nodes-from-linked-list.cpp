class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        // Map to store prefix sums and their corresponding nodes
        HashMap<Integer, ListNode> map = new HashMap<>();
        int currSum = 0;

        // Create a dummy node for easier handling of edge cases
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode temp = dummy;

        // Traverse the linked list
        while (temp != null) {
            currSum += temp.val;

            // If the prefix sum is found in the map
            if (map.containsKey(currSum)) {
                // Get the previous occurrence of this sum
                ListNode prev = map.get(currSum);
                ListNode node = prev.next;

                // Remove nodes between prev and temp from the map
                int sum = currSum;
                while (node != temp) {
                    sum += node.val;
                    map.remove(sum);
                    node = node.next;
                }

                // Skip the zero-sum sublist
                prev.next = temp.next;
            } else {
                // Otherwise, add the current sum to the map
                map.put(currSum, temp);
            }

            // Move to the next node
            temp = temp.next;
        }

        // Return the modified list
        return dummy.next;
    }
}