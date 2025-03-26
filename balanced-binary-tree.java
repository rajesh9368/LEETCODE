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

 // A tree is said to be balanced if for a particular node the left and right height is less than equal to 1.
class Solution {
    public int operation(TreeNode root){
        if(root==null) return 0;
        int left = operation(root.left);
        int right = operation(root.right);
        if(left==-1 || right==-1) return -1;
        if(Math.abs(left-right)>1) return -1;
        return 1+Math.max(left,right);
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        return operation(root)!=-1;
    }
}