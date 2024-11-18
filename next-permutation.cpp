class Solution {
    public void nextPermutation(int[] nums) {
        int pivot = pivotElement(nums);
        if(pivot == -1){
            Arrays.sort(nums);
        }
        else{
            nextGreatestPermutation(nums,pivot);
        }
        return;
    }
    
    private void nextGreatestPermutation(int[] nums, int pivot){
        int swappedIndex = -1;
        int swappedValue = Integer.MAX_VALUE;
        for(int i=nums.length-1;i>pivot;i--){
            if(nums[i]>nums[pivot]){
                int c = nums[i];
                nums[i]= nums[pivot];
                nums[pivot] = c;
                break;
            }
        }
        Arrays.sort(nums,pivot+1, nums.length);
    }
    
    private int pivotElement(int[] nums){
        int pivotIndex = -1;
        for(int i=nums.length-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                pivotIndex = i-1;
                break;
            }
        }
        return pivotIndex;
    }

}