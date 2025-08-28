class Solution {
    public int operation(int i,int buy,int n,int[] prices,int fee){
        if(i>=n) return 0;
        int p=0;
        if(buy==0) p =Math.max(-prices[i]+operation(i+1,1,n,prices,fee),0+operation(i+1,0,n,prices,fee));
        else if(buy==1) p= Math.max(prices[i]-fee+operation(i+1,0,n,prices,fee),0+operation(i+1,1,n,prices,fee));
        return p; 
    }

    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
     return operation(0,0,n,prices,fee);
    }
}