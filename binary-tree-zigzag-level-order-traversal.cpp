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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        int cnt=0;
        List<List<Integer>> arr = new ArrayList<>();
        if(root==null) return arr;
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);
        while(!que.isEmpty()){
            int n = que.size();
            List<Integer> temp = new ArrayList<>();
            for(int i=0;i<n;i++){
                TreeNode curr = que.poll();
                if(cnt%2==0) temp.add(curr.val);
                else temp.add(0,curr.val);
                if(curr.left!=null) que.offer(curr.left);
                if(curr.right!=null) que.offer(curr.right);
            }
            arr.add(temp);
            cnt++;
        }
        return arr;
    }
}