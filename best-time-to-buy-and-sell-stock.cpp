class Solution {
    public int maxProfit(int[] prices) {
        int currmin=prices[0];
        int ans=0;
        for(int i=1;i<prices.length;i++){
            ans=Math.max(ans,prices[i]-currmin);
            currmin=Math.min(currmin,prices[i]);
        }
        return ans;
    }
}