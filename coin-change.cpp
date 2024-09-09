class Solution {
    public int operation(int i, int[] coins, int amount, int[][] dp) {
        if (i == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return Integer.MAX_VALUE - 1;
        }
        if (dp[i][amount] != -1) return dp[i][amount]; 
        int notTake = operation(i - 1, coins, amount, dp);
        int take = Integer.MAX_VALUE - 1; 
        if (coins[i] <= amount)
            take = 1 + operation(i, coins, amount - coins[i], dp);
        return dp[i][amount] = Math.min(notTake, take);
    }
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[][] dp = new int[n][amount + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = -1;
            }
        }
        int ans = operation(n - 1, coins, amount, dp);
        if (ans >= Integer.MAX_VALUE - 1) return -1;
        return ans;
    }
}
