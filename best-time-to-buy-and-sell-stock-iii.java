class Solution {
    //3d DP
    public int operation(int i,int buy,int trans,int[] prices,int[][][] dp){
        if(i==prices.length ||  trans==0) return 0;
        int profit=0;
        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
        if(buy==0)
        profit = Math.max(-prices[i]+operation(i+1,1,trans,prices,dp),0+operation(i+1,0,trans,prices,dp));
        if(buy==1)
        profit = Math.max(prices[i] + operation(i+1,0,trans-1,prices,dp),0+operation(i+1,1,trans,prices,dp));
        return dp[i][buy][trans] =  profit;
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n][2][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return operation(0,0,2,prices,dp);
    }
}