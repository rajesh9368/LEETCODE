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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>(); 
        if (root == null) return result;   
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);                            
        q.add(null);          
        List<Integer> currentLevel = new ArrayList<>();
        while (!q.isEmpty()) {
            TreeNode currNode = q.remove();       
            if (currNode == null) {               
                result.add(new ArrayList<>(currentLevel));
                currentLevel.clear(); 
                if (q.isEmpty()) break;              
                q.add(null);                
            } else {
                currentLevel.add(currNode.val);        
                if (currNode.left != null) q.add(currNode.left);    
                if (currNode.right != null) q.add(currNode.right); 
            }
        }
        return result;                                  
    }
}
