class Solution {
    // public int maxi=0;
    // public boolean checklis(ArrayList<Integer> temp){
    //     for(int i=1;i<temp.size();i++){
    //         if(temp.get(i)<=temp.get(i-1)) return false;
    //     }
    //     return true;
    // }
    // public void operation(int i,int n,int[] nums,ArrayList<Integer> temp){
    //     if(i==n){
    //         if(checklis(temp)){
    //             maxi=Math.max(maxi,temp.size());
    //         }
    //         return;
    //     }
    //     temp.add(nums[i]);
    //     operation(i+1,n,nums,temp);
    //     temp.remove(temp.size()-1);
    //     operation(i+1,n,nums,temp);
    // }
    public int operation(int i,int prev_i,int n,int[] nums,int[][] dp){
        if(i>=n) return 0;
        if(dp[i][prev_i+1]!=-1) return dp[i][prev_i+1];
        int len = operation(i+1,prev_i,n,nums,dp);
        if(prev_i==-1 || nums[i]>nums[prev_i])
        len = Math.max(len,1+operation(i+1,i,n,nums,dp));
        return dp[i][prev_i+1]=len;
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        // lis works on current and previous idx..............................................
        int[][] dp = new int[n][n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        return operation(0,-1,n,nums,dp);
        // return maxi;
    }
}