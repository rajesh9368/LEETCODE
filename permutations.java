class Solution {
    public void operation(int[] nums,List<List<Integer>> ans,ArrayList<Integer> temp,boolean[] map){
        if(nums.length==temp.size()){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(!map[i]){
                map[i] = true;
                temp.add(nums[i]);
                operation(nums,ans,temp,map);
                temp.remove(temp.size()-1);
                map[i] = false;
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        boolean[] map = new boolean[nums.length];
        operation(nums,ans,temp,map);
        return ans;
    }
}