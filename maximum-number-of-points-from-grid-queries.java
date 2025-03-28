class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length;
        int n = grid[0].length;
        int k = queries.length;
        int ans[] = new int[k];

        int dr[] = { 0, -1, 0, 1 };
        int dc[] = { -1, 0, 1, 0 };

        int q2[][] = new int[k][2];
        for (int i = 0; i < k; i++) {
            q2[i] = new int[] { queries[i], i };
        }
        Arrays.sort(q2, Comparator.comparingInt(a -> a[0]));

        PriorityQueue<int[]> que = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
        que.add(new int[] { 0, 0, grid[0][0] });

        int vis[][] = new int[m][n];
        vis[0][0] = 1;

        int p = 0;
        int idx = 0;

        while (idx < k) {
            int q = q2[idx][0];

            while (!que.isEmpty() && que.peek()[2] < q) {
                int a[] = que.remove();
                int r = a[0];
                int c = a[1];

                p += 1;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0) {
                        que.add(new int[] { nr, nc, grid[nr][nc] });
                        vis[nr][nc] = 1;
                    }
                }
            }

            while (idx < k && q2[idx][0] == q) {
                ans[q2[idx][1]] = p;
                idx += 1;
            }
        }
        return ans;
    }
}