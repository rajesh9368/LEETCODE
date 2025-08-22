class Solution {
    public int operation(int i, int j, int[][] obstacleGrid,int[][] dp) {
        if (i < 0 || j < 0) return 0;
        if (obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = operation(i - 1, j, obstacleGrid,dp);
        int left = operation(i, j - 1, obstacleGrid,dp);
        return dp[i][j]=up + left;
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;
        int[][] dp = new int[n+1][m+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        return operation(n-1,m-1,obstacleGrid,dp);
    }
}