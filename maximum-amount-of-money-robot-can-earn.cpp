class Solution {
    public int maximumAmount(int[][] coins) {
        int[][][] dp = new int[coins.length][coins[0].length][3];
        for (int i = 0; i < coins.length; i++) {
            for (int j = 0; j < coins[0].length; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = Integer.MIN_VALUE;
                }
            }
        }
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
            dp[0][0][2] = 0;
        }        
        for (int i = 0; i < coins.length; i++) {
            for (int j = 0; j < coins[0].length; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i][j][k] == Integer.MIN_VALUE) continue;
                    if (i + 1 < coins.length) {
                        dp[i + 1][j][k] = Math.max(dp[i + 1][j][k], dp[i][j][k] + coins[i + 1][j]);
                        if (k + 1 < 3) {
                            dp[i + 1][j][k + 1] = Math.max(dp[i + 1][j][k + 1], dp[i][j][k]);
                        }
                    }
                    if (j + 1 < coins[0].length) {
                        dp[i][j + 1][k] = Math.max(dp[i][j + 1][k], dp[i][j][k] + coins[i][j + 1]);
                        if (k + 1 < 3) {
                           dp[i][j + 1][k + 1] = Math.max(dp[i][j + 1][k + 1], dp[i][j][k]);
                        }
                    }
                }
            }
        }
        int maxProfit = Integer.MIN_VALUE;
        for (int k = 0; k < 3; k++) {
            maxProfit = Math.max(maxProfit, dp[coins.length - 1][coins[0].length - 1][k]);
        }
        return maxProfit;
    }
}