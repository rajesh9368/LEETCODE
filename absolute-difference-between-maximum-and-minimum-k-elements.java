class Solution {
    public int absDifference(int[] nums, int k) {
        int sum1=0,sum2=0;
        Arrays.sort(nums);
        for(int i=0;i<k;i++) sum1 += nums[i];
        for(int i=nums.length-1;i>=nums.length-k;i--) sum2 += nums[i];
        return Math.abs(sum1-sum2);
    }
}