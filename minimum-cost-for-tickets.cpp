class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        Set<Integer> daySet = new HashSet<>();
        for (int i = 0; i < days.length; i++) daySet.add(days[i]);
        int[] dp = new int[366];
        Arrays.fill(dp, -1);
        return solve(1, days, costs, daySet, dp);
    }
    private int solve(int currentDay, int[] days, int[] costs, Set<Integer> daySet, int[] dp) {
        if (currentDay > days[days.length - 1]) return 0;
        if (!daySet.contains(currentDay)) return solve(currentDay + 1, days, costs, daySet, dp);
        if (dp[currentDay] != -1) return dp[currentDay];
        int oneDayPass = costs[0] + solve(currentDay + 1, days, costs, daySet, dp);
        int sevenDayPass = costs[1] + solve(currentDay + 7, days, costs, daySet, dp);
        int thirtyDayPass = costs[2] + solve(currentDay + 30, days, costs, daySet, dp);
        return dp[currentDay] = Math.min(oneDayPass, Math.min(sevenDayPass, thirtyDayPass));
    }
}