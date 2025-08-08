class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int xor1=0,xor2=0;
        for(int i=0;i<n;i++) xor1 = xor1^nums[i];
        for(int i=1;i<=n;i++) xor2 = xor2^i;
        return xor1^xor2;
    }
}