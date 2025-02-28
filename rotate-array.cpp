class Solution {
    public void operation(int[] nums,int start,int end){
        while(start<end){
            int temp = nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        operation(nums,0,n-1);
        operation(nums,0,k-1);
        operation(nums,k,n-1);
    }
}