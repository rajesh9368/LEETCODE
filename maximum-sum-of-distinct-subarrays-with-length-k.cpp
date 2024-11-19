// class Solution {
//     public long maximumSubarraySum(int[] arr, int k) {
//         int maxi = 0;
//         int n = arr.length;
         // for(int i=0;i<=n-k;i++){
//         //     int sum=0;
//         //     HashMap<Integer,Integer> mp = new HashMap<>();
//         //     for(int j=i;j<i+k;j++){
//         //         sum+=arr[j];
//         //         if(!mp.containsKey(arr[j])) mp.put(arr[j],1);
//         //         else mp.put(arr[j],mp.get(arr[j])+1);
//         //     }
//         //     if(mp.size()==k){
//         //         maxi = Math.max(maxi,sum);
//         //         // System.out.println(sum);

//         //     }
//         //     else continue;
//         // }
//         // return maxi;
// }
// }   TLE

class Solution {
    public long maximumSubarraySum(int[] arr, int k) {
        int n = arr.length;
        long maxSum = 0;
        long currentSum = 0;
        int i = 0, j = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        while (j < n) {
            currentSum += arr[j];
            mp.put(arr[j], mp.getOrDefault(arr[j], 0) + 1);
            if (j - i + 1 == k) {
                if (mp.size() == k) {
                    maxSum = Math.max(maxSum, currentSum);
                }
                currentSum -= arr[i];
                mp.put(arr[i], mp.get(arr[i]) - 1);
                if (mp.get(arr[i]) == 0) {
                    mp.remove(arr[i]);
                }
                i++;
            }
            j++;
        }
        return maxSum;
    }
}
