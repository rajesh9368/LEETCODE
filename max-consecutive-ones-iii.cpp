class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int cnt = 0;
        int maxi = 0; 
        for (int i = 0; i < n; i++) {
            cnt = 0;
            int j = i; 
            for (; j < n; j++) {
                if (nums[j] == 0) cnt++;
                if (cnt > k) {
                    break; 
                }
            }
            maxi = Math.max(maxi, j - i); 
        }
        return maxi;
    }
}
