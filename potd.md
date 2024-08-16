#  https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1  -->(Product array puzzle)
***class Solution {
    public static long[] productExceptSelf(int nums[]) {
        // code here
        long[] res = new long[nums.length];
        long pro=1;
        long zerocount=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0)
            pro*=nums[i];
            else zerocount++;
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                if(zerocount>1) res[i]=0;
                else res[i]=pro;
            }
            else{
                if(zerocount>=1) res[i]=0;
                else res[i]=pro/nums[i];
            }
        }
        return res;
    }
}***

# https://www.naukri.com/code360/problems/balanced-sequence-after-replacement_893015?leftPanelTabValue=PROBLEM  -->(Balanced Sequence After Replacement)
******
