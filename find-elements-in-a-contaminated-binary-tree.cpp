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
class FindElements {
    TreeNode root;
    BitSet sett;

    public void inorder(TreeNode root, int val) {
        if (root == null) return;
        root.val = val;
        sett.set(val);
        inorder(root.left, 2 * val + 1);
        inorder(root.right, 2 * val + 2);
    }

    public FindElements(TreeNode root) {
        this.root = root;
        sett = new BitSet();
        inorder(this.root, 0);
    }

    public boolean find(int target) {
        return sett.get(target);
    }
}


/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */