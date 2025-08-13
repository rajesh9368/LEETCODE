class Solution {
    public int operation(int i,int[] nums,int[] dp){
        if(i>=nums.length) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i]+operation(i+2,nums,dp);
        int unpick = operation(i+1,nums,dp);
        dp[i]=Math.max(pick,unpick);
        return dp[i];
    }
    public int rob(int[] nums) {
        int[] dp = new int[nums.length+1];
        Arrays.fill(dp,-1);
        int sum = operation(0,nums,dp);
        return sum;
    }
}