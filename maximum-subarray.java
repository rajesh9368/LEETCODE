class Solution {
    public int maxSubArray(int[] nums) {
        //tc:o(n)
        //sc:o(n)
      int n = nums.length;
    //   int[] prefix = new int[n];
    //   prefix[0] = nums[0];
    //   for(int i=1;i<n;i++) prefix[i]=Math.max(prefix[i-1]+nums[i],nums[i]);
    //   int maxi = Integer.MIN_VALUE;
    //   for(int i=0;i<n;i++){
    //     if(maxi<prefix[i]) maxi=prefix[i];
    //   }
    //   return maxi;
    //tc:o(n)
    //sc:o(1)
    int currsum=0;
    int maxi=nums[0];
    for(int i=0;i<n;i++){
        currsum=Math.max(currsum+nums[i],nums[i]);
        maxi=Math.max(currsum,maxi);
    }
    return maxi;
    }
}