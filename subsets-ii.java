class Solution {
   public void operation(int n,int[] nums,int i,ArrayList<Integer> temp,List<List<Integer>> ans){
        if(i>=n){
            if(!ans.contains(new ArrayList<>(temp)))
            ans.add(new ArrayList<>(temp));
            return;
        }
        temp.add(nums[i]);
        operation(n,nums,i+1,temp,ans);
        temp.remove(temp.size()-1);
        operation(n,nums,i+1,temp,ans);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        ArrayList<Integer> temp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        operation(n,nums,0,temp,ans);
        return ans;
    }
}
