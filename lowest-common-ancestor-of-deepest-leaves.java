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
    public TreeNode lcaDeepestLeaves(TreeNode root) {

        //calculate parents for each node
        Map<TreeNode, TreeNode> map = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()) {
            TreeNode cur = queue.poll();
            if(cur.left!=null) {
                map.put(cur.left, cur);
                queue.add(cur.left);
            }
            if(cur.right!=null) {
                map.put(cur.right, cur);
                queue.add(cur.right);
            }
        }
        map.put(root, null);
        
        // find the nodes which are deepest leaves using depth and store them in a hashset
        Set<TreeNode> set = new HashSet<>();
        int[] maxDepth = {0};
        calculateDepth(root,set,0, maxDepth);  

        //traverse upwards from the leaf nodes using parent map   
    
        while(set.size()>1) {
            Set<TreeNode> parents = new HashSet<>();
            for(TreeNode node:set) {
                parents.add(map.get(node));
            }
            set = parents;
        }

        return set.iterator().next();
    }

    public void calculateDepth(TreeNode root, Set<TreeNode> set, int depth, int[] maxDepth) {
        if(depth==maxDepth[0]) {
            set.add(root);
        } else if(depth>maxDepth[0]) {
            maxDepth[0] = depth;
            set.clear();
            set.add(root);
        }
        if(root.left!=null) {
            calculateDepth(root.left, set, depth+1, maxDepth);
        }
        if(root.right!=null) {
            calculateDepth(root.right, set, depth+1, maxDepth);
        }
    }
}