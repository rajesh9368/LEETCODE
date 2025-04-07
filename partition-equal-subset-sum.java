class Solution {
    public int operation(int n,int[] nums,int sum,int i,int target,int[][] dp){
        if(target==0) return 1;
        if(i==n) return 0; 
        int pick=0;
        if(dp[i][target]!=-1) return dp[i][target];
        if(nums[i]<=target)
        pick = operation(n,nums,sum,i+1,target-nums[i],dp);
        int unpick=operation(n,nums,sum,i+1,target,dp);
        return dp[i][target]=(pick+unpick)%100000007;
    }
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum=0,ans=0,totalsum=0;
        for(int i=0;i<nums.length;i++) totalsum+=nums[i];
        if(totalsum%2!=0) return false;
        else{
            sum=totalsum/2;
            int[][] dp = new int[n+1][sum+1];
            for(int[] row:dp) Arrays.fill(row,-1);
            ans=operation(n,nums,sum,0,sum,dp);
            if(ans>0) return true;
        }
        return false;
    }
}