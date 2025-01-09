class Solution {
    public int operation(int m, int n, int i, int j, int[][] dp) {
        if (i == m - 1 && j == n - 1) return 1;
        if (i >= m || j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int right = operation(m, n, i, j + 1, dp);
        int bottom = operation(m, n, i + 1, j, dp);
        return dp[i][j] = right + bottom;
    }

    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        return operation(m, n, 0, 0, dp);
    }
}
