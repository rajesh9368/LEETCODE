class Solution {
    public boolean canJump(int[] nums) {
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(cnt<0) return false;
            else if(nums[i]>cnt) cnt=nums[i];
            cnt--;
        }
        return true;
    }
}