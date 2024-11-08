class Solution {
    public int[] getMaximumXor(int[] nums, int max) {
        int n=nums.length;
        int []pre=new int [n];
        pre[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            pre[i]=pre[i-1]^nums[i];
        }
        int []res=new int [n];
        int z=(int) Math.pow(2,max)-1;
        for(int i=0;i<nums.length;i++){
              res[i]= pre[n-i-1]^z;
        }
        return res;
        
    }
}