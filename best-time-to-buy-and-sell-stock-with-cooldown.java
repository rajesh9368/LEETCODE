class Solution {
    public int operation(int i,int buy,int n,int[] prices,int[][] dp){
        if(i>=n) return 0;
        int p=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==0) p =Math.max(-prices[i]+operation(i+1,1,n,prices,dp),0+operation(i+1,0,n,prices,dp));
        else if(buy==1) p= Math.max(prices[i]+operation(i+2,0,n,prices,dp),0+operation(i+1,1,n,prices,dp));
        return dp[i][buy] = p; 
    }
    public int maxProfit(int[] prices) {
     int n = prices.length;
     int[][] dp = new int[n][2];
     for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=-1;
        }
     }
     return operation(0,0,n,prices,dp);   
    }
}