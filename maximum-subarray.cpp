class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length==0) return 0;
        int n = nums.length;
        int[] prefix = new int[n];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)prefix[i]=Math.max(prefix[i-1]+nums[i],nums[i]);
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<n;i++) {
            if(maxi<prefix[i]) maxi=prefix[i];
        }
        return maxi;
    }
}

