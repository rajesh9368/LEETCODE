class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int[]arr = new int[nums.length];
        int n = nums.length;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) arr[i]=nums[i];
            else {
                int s=nums[i];
                int t=(i + s % n + n) % n; arr[i]=nums[t];
            }
        }
        return arr;
    }

}