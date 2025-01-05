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
    public void operation1(TreeNode root1,List<Integer> temp){
        if(root1==null) return;
        operation1(root1.left,temp);
        temp.add(root1.val);
        operation1(root1.right,temp);
    }
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> temp1 = new ArrayList<>();
        List<Integer> temp2 = new ArrayList<>();
        operation1(root1,temp1);
        operation1(root2,temp2);
        List<Integer> arr = new ArrayList<>();
        for(int i=0;i<temp1.size();i++) arr.add(temp1.get(i));
        for(int i=0;i<temp2.size();i++) arr.add(temp2.get(i));
        Collections.sort(arr);
        return arr;
    }
}