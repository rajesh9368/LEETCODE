// class Solution {
//     public long countFairPairs(int[] arr, int lower, int upper) {
//         // HashMap<Integer,Integer> mp = new HashMap<>();
//         // int n = arr.length;
//         // int cnt=0;
//         // for(int i=0;i<n-1;i++){
//         //     for(int j=i+1;j<n;j++){
//         //         int ans = arr[i]+arr[j];
//         //         if(ans>=lower && ans<=upper){
//         //             if(!mp.containsKey(i) || mp.get(i) != j){
//         //                 mp.put(i,j);
//         //                 // System.out.println(i+" "+j);
//         //                 cnt++;
//         //             }
//         //         }
//         //     }
//         // }
//         // return cnt;  TLE
// }
//     }
//    
class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        return smaller(nums, upper) - smaller(nums, lower - 1);     
    }
    private long smaller(int[] nums, int value) {
        int l = 0, r = nums.length - 1;
        long result = 0;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum <= value) {
                result += (r - l);
                l++;   
            } else {    
                r--;
            }
        }
        return result;
    }
}