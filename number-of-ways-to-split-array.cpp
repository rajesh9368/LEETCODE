// class Solution {
//     public int waysToSplitArray(int[] arr) {
//         int n = arr.length;
//         int cnt=0,sum1=0,sum2=0;
//         for(int i=0;i<n;i++){
//             sum1+=arr[i];
//             sum2=0;
//             for(int j=i+1;j<n;j++){
//                 sum2+=arr[j];
//                 if(sum1>=sum2){
//                     cnt++;
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// } //wrong answer
class Solution {
    public int waysToSplitArray(int[] arr) {
        int n = arr.length;
        long totalSum = 0, sum1 = 0;
        int cnt = 0;
        for (int i=0;i<n;i++) totalSum +=arr[i];
        for (int i = 0; i < n - 1; i++) {
            sum1 += arr[i]; 
            long sum2 = totalSum - sum1; 
            if (sum1 >= sum2) cnt++;
        }
        return cnt;
    }
}
