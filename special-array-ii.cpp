class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        boolean[] answer = new boolean[queries.length];
        boolean[] parityChange = new boolean[n - 1];
        for (int i = 0; i < n - 1; i++)
            parityChange[i] = (nums[i] % 2) != (nums[i + 1] % 2);
        int[] cumSum = new int[n];
        cumSum[0] = 0;
        for (int i = 1; i < n; i++) 
            cumSum[i] = cumSum[i - 1] + (parityChange[i - 1] ? 1 : 0);
        for (int i = 0; i < queries.length; i++) {
            int from = queries[i][0];
            int to = queries[i][1];
            int parityChangesInRange = cumSum[to] - cumSum[from];
            answer[i] = (parityChangesInRange == (to - from));
        }
        return answer;
    }
}


