class Solution {
    public int countSubarrays(int[] nums) {
        int n = nums.length;
        if(n<3) return 0;
        int ans=0;
        int i=0;
        while(i<=n-3){
            int f = nums[i],s=nums[i+1],t=nums[i+2];
            if(f+t==s/2.0) ans++;
            i++;
        }
        return ans;
    }
}