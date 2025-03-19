class Solution {
    public void operation(int[] candidates,int target,int i,ArrayList<Integer> temp,List<List<Integer>> ans){
        if(i==candidates.length){
        if(target==0) ans.add(new ArrayList<>(temp));
        return;
        }
        if(candidates[i]<=target){
            temp.add(candidates[i]);
            operation(candidates,target-candidates[i],i,temp,ans);
            temp.remove(temp.size()-1);
        }
        operation(candidates,target,i+1,temp,ans);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int n = candidates.length;
        ArrayList<Integer> temp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        operation(candidates,target,0,temp,ans);
        return ans;
    }
}