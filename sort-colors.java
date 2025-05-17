class Solution {
    public void sortColors(int[] nums) {
        //tc:o(4n)
        //sc:o(1)
        int n = nums.length;
        // int cnt0=0,cnt1=0,cnt2=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0) cnt0++;
        //     else if(nums[i]==1) cnt1++;
        //     else cnt2++;
        // }
        // for(int i=0;i<cnt0;i++) nums[i]=0;
        // for(int i=cnt0;i<cnt0+cnt1;i++) nums[i]=1;
        // for(int i=cnt0+cnt1;i<n;i++) nums[i]=2;

        // a variant of Dutch national Flag problem Algorithm
        //tc:o(n)
        //Sc:o(n)
        int left=0,right=n-1,mid=0;
        while(mid<=right){
            if(nums[mid]==2){
                int temp = nums[mid];
                nums[mid] = nums[right];
                nums[right] = temp;
                right--;
            }
            else if(nums[mid]==1) mid++;
            else if(nums[mid]==0) {
                int temp = nums[mid];
                nums[mid] = nums[left];
                nums[left] = temp;
                left++;
                 mid++;
            }
        }
    }
}