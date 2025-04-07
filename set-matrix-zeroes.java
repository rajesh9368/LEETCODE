class Solution {
    public void setZeroes(int[][] matrix) {
        //tc:o(n*m)+o(n*m) = 2*o(n*m)
        //sc:o(n)+o(m)
        int n = matrix.length;
        int m = matrix[0].length;
        int[] row = new int[n]; //hash row Array
        int[] col = new int[m]; // hash column Array
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=-1;
                    col[j]=-1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==-1 || col[j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
}