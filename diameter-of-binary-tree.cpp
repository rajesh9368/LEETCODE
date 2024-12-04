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
// class Solution {
//     public int height(TreeNode root){
//         if(root == null) return 0;
//         int left = height(root.left);
//         int right = height(root.right);
//         return Math.max(left,right)+1;
//     }
//     public int diameterOfBinaryTree(TreeNode root) {
//         if(root==null) return 0;
//         int d1 = diameterOfBinaryTree(root.left);
//         int d2 = diameterOfBinaryTree(root.right);
//         int d3 = height(root);
//         return Math.max(d3,Math.max(d1,d2));
//     }
// }

class Solution {
    public int height(TreeNode root) {
        if (root == null) return 0;
        int left = height(root.left);
        int right = height(root.right);
        return Math.max(left, right) + 1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);
        int d3 = leftHeight + rightHeight;
        int d1 = diameterOfBinaryTree(root.left);
        int d2 = diameterOfBinaryTree(root.right);
        return Math.max(d3, Math.max(d1, d2));
    }
}
