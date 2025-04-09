class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]<k) return -1;
        }
        Arrays.sort(nums);
        int i=n-1;
        int cnt=0;
        while(i>=0&&nums[i]>k){
            int prev=nums[i];
            cnt++;
        while(i>=0&&nums[i]==prev) i--;
        }
        return cnt;
    }
}