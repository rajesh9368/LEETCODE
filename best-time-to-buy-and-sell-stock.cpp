class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        int current=prices[0],benefit=0;
        for(int i=1;i<n;i++){
            if(current>prices[i]) current=prices[i];
            benefit=Math.max(benefit,prices[i]-current);
        }
        return benefit;
    }
}