class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long[] prefixSum = new long[n + 1];
        prefixSum[0] = 0;

        // Compute prefix sums
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        Map<Integer, Long> remainderMap = new HashMap<>();
        long maxSum = Long.MIN_VALUE;

        // Iterate over prefix sums
        for (int i = 0; i <= n; i++) {
            int remainder = i % k;

            // Check if the same remainder exists
            if (remainderMap.containsKey(remainder)) {
                maxSum = Math.max(maxSum, prefixSum[i] - remainderMap.get(remainder));
            }

            // Update the minimum prefix sum for this remainder
            remainderMap.put(remainder, Math.min(remainderMap.getOrDefault(remainder, Long.MAX_VALUE), prefixSum[i]));
        }

        return maxSum == Long.MIN_VALUE ? 0 : maxSum;
    }

}
