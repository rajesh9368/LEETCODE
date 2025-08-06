class Solution {
     public void operation(int k,int num,int target,List<List<Integer>> ans,ArrayList<Integer> res){
            if(target==0 && k==0) {
                ans.add(new ArrayList<>(res));
            return;
            }
    for(int i=num;i<10;i++){
        if(i>target || k<=0 ) break;
            res.add(i);
            operation(k-1,i+1,target-i,ans,res);
            res.remove(res.size()-1);
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> res = new ArrayList<>();
        operation(k,1,n,ans,res);
        return ans;
    }
}