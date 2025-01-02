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
    public int operation(TreeNode root){
        if(root==null) return 0;
        int left = operation(root.left);
        int right = operation(root.right);
        return 1+Math.max(left,right);
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;
        int left = operation(root.left);
        int right = operation(root.right);
        if(Math.abs(left-right)<=1 && isBalanced(root.left) && isBalanced(root.right)) return true;
        return false;
    }
}