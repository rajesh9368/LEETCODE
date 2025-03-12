class Solution {
    public int maximumCount(int[] nums) {
        int maxi=0,neg=0,pos=0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]>0) pos++;
            else if(nums[i]<0) neg++;
        }
        maxi = Math.max(neg,pos);
        return maxi;
    }
}