class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int maxi = nums[0],mini = nums[0];
        int currmin = nums[0],currmax = nums[0],totalsum=nums[0];
        for(int i=1;i<nums.length;i++){
            currmax = Math.max(nums[i],currmax+nums[i]);
            maxi = Math.max(maxi,currmax);
            currmin = Math.min(nums[i],currmin+nums[i]);
            mini = Math.min(mini,currmin);
            totalsum+=nums[i];
        }
        if(maxi<0) return maxi;
        return Math.max(maxi,totalsum - mini);
    }
}