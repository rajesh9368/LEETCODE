class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] diff = new int[n + 2];

        for (int[] q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;
        }

        int qmlsum = 0;
        for (int i = 0; i < n; i++) {
            qmlsum += diff[i];
            if (nums[i] > qmlsum) {
                return false;
            }
        }

        return true;
    }
}
