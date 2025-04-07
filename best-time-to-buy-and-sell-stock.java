class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int maxiprofit = 0;
        int currmin = prices[0];
        for(int i=1;i<n;i++){
            maxiprofit = Math.max(maxiprofit,prices[i]-currmin);
            currmin = Math.min(currmin,prices[i]);
        }
        return maxiprofit;
    }
}