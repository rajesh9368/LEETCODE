class Solution {
    public int operation(int i,int buy,int k,int n,int[] prices,int[][][] dp){
        if(i==n || k==0) return 0;
        int profit=0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if(buy==0) profit = Math.max(-prices[i]+operation(i+1,1,k,n,prices,dp),0+operation(i+1,0,k,n,prices,dp));
        else if(buy==1) profit = Math.max(prices[i] + operation(i+1,0,k-1,n,prices,dp) ,operation(i+1,1,k,n,prices,dp));
        return dp[i][buy][k]=profit;
    }
    public int maxProfit(int k, int[] prices) {
     int n = prices.length;
     int[][][] dp = new int[n][2][k+1];
     for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int a=0;a<=k;a++){
                dp[i][j][a]=-1;
            }
        }
     }
     return operation(0,0,k,n,prices,dp);   
    }
}