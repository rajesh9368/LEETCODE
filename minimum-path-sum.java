class Solution {
    public int operation(int n,int m,int[][] grid,int[][] dp){
        if(n<0 || m<0) return Integer.MAX_VALUE;
        if(n==0 && m==0) return grid[0][0];
        if(dp[n][m]!=-1) return dp[n][m];
        int up = operation(n-1,m,grid,dp);
        int left =operation(n,m-1,grid,dp);
        return dp[n][m]=grid[n][m]+Math.min(up,left);
     }
    public int minPathSum(int[][] grid) {
        int n = grid.length,m=grid[0].length;
        int[][] dp = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = -1;
            }
        }
        return operation(n-1,m-1,grid,dp);
    }
}