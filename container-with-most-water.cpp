class Solution {
    public int maxArea(int[] nums) {
        int i=0,j=nums.length-1;
        int max = Integer.MIN_VALUE;
        while(i<j){
            max=Math.max(max,(Math.min(nums[i],nums[j])*(j-i)));
            // max=Math.max(max,(Math.min(height[i],height[j])*(j-i)));
            if(nums[i]<nums[j]) i++;
            else j--;
        }
        return max;
    }
}