class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
        Deque<int[]> deque = new ArrayDeque<>();
        int[][] cost = new int[m][n];

        for (int i = 0; i < m; i++) {
            Arrays.fill(cost[i], Integer.MAX_VALUE);
        }

        deque.offer(new int[]{0, 0});
        cost[0][0] = 0;

        while (!deque.isEmpty()) {
            int[] current = deque.pollFirst(); 
            int x = current[0];
            int y = current[1];
            int currentCost = cost[x][y];
            int direction = grid[x][y] - 1;

            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = currentCost + (i != direction ? 1 : 0);

                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;

                        if (i == direction) {
                            deque.addFirst(new int[]{nx, ny}); 
                        } else {
                            deque.addLast(new int[]{nx, ny}); 
                        }
                    }
                }
            }
        }
        return cost[m - 1][n - 1];
    }
}