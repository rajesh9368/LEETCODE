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
    // public int minimumOperations(TreeNode root) {
    //     int res = 0;
    //     Queue<TreeNode> q = new ArrayDeque<TreeNode>();
    //     q.add(root);
    //     while (!q.isEmpty()) {
    //         int n = q.size();
    //         List<Integer> list = new ArrayList<Integer>();
    //         while (n-- > 0) {
    //             TreeNode curr = q.remove();
    //             if (curr.left != null) q.add(curr.left);
    //             if (curr.right != null) q.add(curr.right);
    //             list.add(curr.val);
    //         }
    //         res += minSwaps(list);
    //     }
    //     return res;
    // }
    // int minSwaps(List<Integer> list) {
    //     int swaps = 0, n = list.size();
    //     List<Integer> sorted = new ArrayList<Integer>();
    //     sorted.addAll(list);
    //     Collections.sort(sorted);
    //     for (int i = 0; i < n; i++) {
    //         if (list.get(i) != sorted.get(i)) {
    //             ++swaps;
    //             Collections.swap(list, i, list.indexOf(sorted.get(i)));
    //         }
    //     }
    //     return swaps; tle
    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int totalSwaps = 0;
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            int[] levelValues = new int[levelSize];
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                levelValues[i] = node.val;

                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            totalSwaps += getMinSwaps(levelValues);
        }
        return totalSwaps;
    }
    private int getMinSwaps(int[] original) {
        int swaps = 0;
        int[] target = original.clone();
        Arrays.sort(target);
        Map<Integer, Integer> pos = new HashMap<>();
        for (int i = 0; i < original.length; i++) {
            pos.put(original[i], i);
        }
        for (int i = 0; i < original.length; i++) {
            if (original[i] != target[i]) {
                swaps++;
                int curPos = pos.get(target[i]);
                pos.put(original[i], curPos);
                original[curPos] = original[i];
            }
        }
        return swaps;
    }
}