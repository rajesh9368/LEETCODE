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
    public void operation(TreeNode root,ArrayList<Integer> arr){
        if(root==null) return;
        operation(root.left,arr);
        arr.add(root.val);
        operation(root.right,arr);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        operation(root,arr);
        return arr;
    }
}