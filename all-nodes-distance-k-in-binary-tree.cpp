/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    List<Integer> result = new ArrayList<>();
    Map<TreeNode,TreeNode> parentmap = new HashMap<>();
    Set<TreeNode> visited = new HashSet<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        buildmap(root);
        FindTarget(target,0,k);
        return result;
    }

    public void buildmap(TreeNode node){
        if(node.left != null){
            parentmap.put(node.left,node);
            buildmap(node.left);
        }
        if(node.right != null){
            parentmap.put(node.right,node);
            buildmap(node.right);
        }
    }

    public void FindTarget(TreeNode node ,int distance , int k){

       if(node == null || visited.contains(node)){
        return;
       }
       visited.add(node);
       
        if(distance == k){
            result.add(node.val);
            return ;
        }
       
            FindTarget(node.left,distance+1,k);
        
        
            FindTarget(node.right,distance+1,k);
        
        
            FindTarget(parentmap.get(node),distance+1,k);
        
         visited.remove(node);
    }
}