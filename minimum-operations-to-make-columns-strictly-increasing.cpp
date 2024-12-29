class Solution {
    public int minimumOperations(int[][] grid) {
        int cnt=0;
        int m = grid.length,n = grid[0].length;  
        for (int j=0;j<n;j++) {
        for (int i=1; i<m; i++) {
                if (grid[i][j]<= grid[i - 1][j]) {
                    int op=grid[i - 1][j]-grid[i][j]+1;
                      cnt+=op;
                    grid[i][j]+=op;}}}
        return cnt; 
    }
}