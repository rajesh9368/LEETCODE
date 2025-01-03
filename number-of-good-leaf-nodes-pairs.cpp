class Solution {
    

    private void calculatePathsToLeafNodes(List<TreeNode> temp, TreeNode root, 
                                           Map<TreeNode, List<TreeNode>> pathMap, 
                                           List<TreeNode> leafNodes) {
        if (root == null) return;

        // Leaf node
        if (root.left == null && root.right == null) {
            temp.add(root);
            leafNodes.add(root);
            pathMap.put(root, new ArrayList<>(temp));
            temp.remove(temp.size() - 1);
            return;
        }

        temp.add(root);
        calculatePathsToLeafNodes(temp, root.left, pathMap, leafNodes);
        calculatePathsToLeafNodes(temp, root.right, pathMap, leafNodes);
        temp.remove(temp.size() - 1);
    }

    private int calculateShortestPath(List<TreeNode> path1, List<TreeNode> path2) {
        int size1 = path1.size(), size2 = path2.size();
        int forwardPath = 0, backwardPath = 0;

        for (int i = 0; i < Math.min(size1, size2); i++) {
            if (!path1.get(i).equals(path2.get(i))) {
                forwardPath = size1 - i;
                backwardPath = size2 - i;
                break;
            }
        }
        return forwardPath + backwardPath;
    }

    public int countPairs(TreeNode root, int distance) {
        // Map to store paths from root to each leaf node
        Map<TreeNode, List<TreeNode>> pathMap = new HashMap<>();
        List<TreeNode> leafNodes = new ArrayList<>();
        List<TreeNode> tempPath = new ArrayList<>();

        // Calculate paths to all leaf nodes
        calculatePathsToLeafNodes(tempPath, root, pathMap, leafNodes);

        int count = 0;

        // Compare paths of every pair of leaf nodes
        for (int i = 0; i < leafNodes.size(); i++) {
            for (int j = i + 1; j < leafNodes.size(); j++) {
                List<TreeNode> path1 = pathMap.get(leafNodes.get(i));
                List<TreeNode> path2 = pathMap.get(leafNodes.get(j));

                int shortestPath = calculateShortestPath(path1, path2);

                if (shortestPath <= distance) {
                    count++;
                }
            }
        }

        return count;
    }
}

//shortest distance b/w two nodes: distance b/w lca and first+distance b/w lca and 2nd

//tree can contain duplicate values