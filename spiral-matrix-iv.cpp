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
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] arr = new int[m][n];
        // Initialize the matrix with -1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = -1;
            }
        }

        int tr = 0, lc = 0, rc = n - 1, br = m - 1;
        
        while (head != null) {
        
            for (int i = lc; i <= rc && head != null; i++) {
                arr[tr][i] = head.val;
                head = head.next;
            }
            tr++;

            
            for (int i = tr; i <= br && head != null; i++) {
                arr[i][rc] = head.val;
                head = head.next;
            }
            rc--;

           
            for (int i = rc; i >= lc && head != null; i--) {
                arr[br][i] = head.val;
                head = head.next;
            }
            br--;

            for (int i = br; i >= tr && head != null; i--) {
                arr[i][lc] = head.val;
                head = head.next;
            }
            lc++;
        }
        
        return arr;
    }
}
