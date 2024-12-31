class Solution {
    public TreeNode operation(int[] postorder, int postst, int postend, int[] inorder, int inst, int inend, Map<Integer, Integer> mp) {
        if (postst > postend || inst > inend) return null;
        TreeNode root = new TreeNode(postorder[postend]);
        int inroot = mp.get(root.val);
        int numsleft = inroot - inst;
        root.left = operation(postorder, postst, postst + numsleft - 1, inorder, inst, inroot - 1, mp);
        root.right = operation(postorder, postst + numsleft, postend - 1, inorder, inroot + 1, inend, mp);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            mp.put(inorder[i], i);
        }
        return operation(postorder, 0, postorder.length - 1, inorder, 0, inorder.length - 1, mp);
    }
}
