/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int cnt; // Declare a class-level variable for counting good nodes

    public void operation(TreeNode root, int max) {
        if (root != null) {
            if (root.val >= max) {
                cnt++; // Increment the count for a good node
                max = root.val; // Update the max for this path
            }
            operation(root.left, max); // Recur for the left child
            operation(root.right, max); // Recur for the right child
        }
    }

    public int goodNodes(TreeNode root) {
        cnt = 0; // Initialize the count to 0
        operation(root, root.val); // Start the recursion
        return cnt; // Return the final count
    }
}
