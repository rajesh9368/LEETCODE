class Solution {
    public List<Integer> zigzagTraversal(int[][] grid) {
        ArrayList<Integer> arr = new ArrayList<>();
        int n = grid.length;
        int m = grid[0].length;
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<m;j++) arr.add(grid[i][j]);
            }
            else{
                for(int j=m-1;j>=0;j--) arr.add(grid[i][j]);
            }
        }
        ArrayList<Integer> a1 = new ArrayList<>();
        for(int i=0;i<arr.size();i+=2) a1.add(arr.get(i));
        return a1;
    }
}