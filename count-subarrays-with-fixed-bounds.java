class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long ans=0;
        int end=-1;
        int minind=-1;
        int maxind=-1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>maxK || nums[i]<minK){
                end=i;
            }
            if(nums[i]==minK){
                minind=i;
            }
            if(nums[i]==maxK){
                maxind=i;
            }
            ans+=Math.max(0,Math.min(maxind,minind)-end);
        }
        return ans;
    }
}