import java.util.Arrays;

class Solution {
    static int operation(int[] nums, int i, int[] dp) {
        int n = nums.length;
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int pick = nums[i] + operation(nums, i + 2, dp);
        int nonpick = operation(nums, i + 1, dp);
        return dp[i] = Math.max(pick, nonpick);
    }
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n]; 
        Arrays.fill(dp, -1);
        return operation(nums, 0, dp);
    }
}
