class Solution {
    public static void Met(int i,int[]nums,List<List<Integer>>a,List<Integer>ds)
    {
        if(i==nums.length){
            if(!a.contains(new ArrayList<>(ds)))
            {
            a.add(new ArrayList<>(ds));
                
            }
            return;
        }
        ds.add(nums[i]);
        Met(i+1,nums,a,ds);
        ds.remove(ds.size()-1);
        Met(i+1,nums,a,ds);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>>a=new ArrayList<>();
        Met(0,nums,a,new ArrayList<>());
        return a;
    }
}