class Solution {
    public void operation(int[] candidates,int target,int n,List<List<Integer>> ans,ArrayList<Integer> res,int i){
        if(i==n){
            if(target==0 && !ans.contains(res)) ans.add(new ArrayList<>(res));
            return;
        }
        if(candidates[i]<=target){
            res.add(candidates[i]);
            operation(candidates,target-candidates[i],n,ans,res,i+1);
            res.remove(res.size()-1);
        }
        operation(candidates,target,n,ans,res,i+1);
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        int n = candidates.length;
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> res = new ArrayList<>();
        operation(candidates,target,n,ans,res,0);
        return ans;
    }
}