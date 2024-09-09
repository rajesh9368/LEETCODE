class Solution {
    public int[] sortedSquares(int[] nums) {
        int n  = nums.length;
        int [] ans = new int[n];
        int l=0,r=n-1;
        int idx=n-1;
        while(l<=r){
            int left = nums[l]*nums[l];
            int right = nums[r]*nums[r];
            if(left>right){
                ans[idx]=left;
                l++;
            }
            else{
                ans[idx]=right;
                r--;
            }
            idx--;
        }
        return ans;
    }
}