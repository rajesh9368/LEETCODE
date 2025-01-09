class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        int dp[]=new int[n+1];
        Arrays.fill(dp,-1); 
        //from index 0 to n-1 to ignore the last house
        int firstHouse = leavemealone(nums,0,n-1,dp);
        //Now we have to reinitialise the dp array to -1
        Arrays.fill(dp,-1); 
        //Now to ignore the first house we will iterate from 1 to n
        int lastHouse = leavemealone(nums,1,n,dp);
        return Math.max(firstHouse,lastHouse);
    }

     public int leavemealone(int[] nums, int idx, int n, int dp[]){
       if(idx>=n){
           return 0;
       }
       if(dp[idx]!=-1){
           return dp[idx];
       }
       return dp[idx]=Math.max(nums[idx] + leavemealone(nums,idx+2,n,dp), 0 + leavemealone(nums,idx+1,n,dp));
    }
}