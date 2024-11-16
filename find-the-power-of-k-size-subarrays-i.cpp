class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int maxi=Integer.MIN_VALUE;
        int[] ans = new int[nums.length-k+1];
        for(int i=0;i<=nums.length-k;i++){
            boolean flag=true;
            for(int j=i;j<i+k-1;j++){
                    if(nums[j+1]!=nums[j]+1){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans[i]=nums[i+k-1];
                else ans[i]=-1;
        }
        return ans;
    }
}