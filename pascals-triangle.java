class Solution {
    public int operation(int r,int c){
        int res = 1;
        for(int i=0;i<c;i++){
            res = res*(r-i);
            res=res/(i+1);
        }
        return res;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            ArrayList<Integer> temp = new ArrayList<>();
            for(int j=0;j<=i;j++){
                temp.add(operation(i,j));
            }
            ans.add(temp);
        } 
        return ans;
    }
}