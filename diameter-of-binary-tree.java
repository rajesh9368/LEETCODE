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
 //diameter is the longest length between any two node for a given tree.
class Solution {
    public int operation(TreeNode root,int[] diameter){
        if(root==null) return 0;
        int left = operation(root.left,diameter);
        int right = operation(root.right,diameter);
        diameter[0] = Math.max(diameter[0],left+right);
        return 1+Math.max(left,right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int[] diameter = new int[1];
        operation(root,diameter);
        return diameter[0];
    }
}