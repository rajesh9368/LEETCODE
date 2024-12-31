import java.util.HashMap;
import java.util.Map;

class Solution {
    public TreeNode operation(int[] preorder, int prest, int preend, int[] inorder, int inst, int inend, Map<Integer, Integer> mp) {
        if (prest > preend || inst > inend) return null;
        TreeNode root = new TreeNode(preorder[prest]);
        int inroot = mp.get(root.val);
        int numsleft = inroot - inst;
        root.left = operation(preorder, prest + 1, prest + numsleft, inorder, inst, inroot - 1, mp);
        root.right = operation(preorder, prest + numsleft + 1, preend, inorder, inroot + 1, inend, mp);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            mp.put(inorder[i], i);
        }
        return operation(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, mp);
    }
}
