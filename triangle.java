class Solution {
    public int operation(int i,int j,List<List<Integer>> triangle){
        int n = triangle.size();
        if(i==n-1) return triangle.get(n-1).get(j);
        int down = operation(i+1,j,triangle);
        int diagonal = operation(i+1,j+1,triangle);
        return triangle.get(i).get(j) + Math.min(down,diagonal);
    }
    public int minimumTotal(List<List<Integer>> triangle) {
        return operation(0,0,triangle);
    }
}