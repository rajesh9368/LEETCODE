class Solution {
    public boolean canSortArray(int[] nums) {
        int n = nums.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    int curr = Integer.bitCount(nums[i]);
                    int next = Integer.bitCount(nums[j]);
                    if(curr!=next) return false; //like in case of 8 and 3
                    else{
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
}