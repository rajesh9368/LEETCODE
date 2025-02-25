class Solution {
    public int numOfSubarrays(int[] nums) {
        int oddCount = 0;
        int evenCount = 1;
        int sum = 0;
        int result = 0;
        int mod= 1000000007;
        for(int i = 0;i<nums.length;i++){
            // first fuinf the sum
            sum = sum+ nums[i];
            if(sum%2 == 0){
                result = (result +oddCount)%mod;
                evenCount++;
            }else{
                result = (result + evenCount)%mod;
                oddCount++;
            }
        }
        return result;

    }
}