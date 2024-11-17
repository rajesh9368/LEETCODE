// class Solution {
//     public int shortestSubarray(int[] nums, int k) {
//         int mini=Integer.MAX_VALUE;
//         int n = nums.length;
//         int cnt=-1;
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                     sum+=nums[j];
//                     if(sum>=k) mini=Math.min(mini,j-i+1);
//             }
//         }
//         if(mini == Integer.MAX_VALUE)return -1;
//         return mini;
//     }
// }  TLE

class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] pre = new long[n + 1];
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        
        Deque<Integer> dq = new LinkedList<>();
        int res = Integer.MAX_VALUE;

        for (int i = 0; i <= n; i++) {
            while (!dq.isEmpty() && pre[i] - pre[dq.peekFirst()] >= k) {
                res = Math.min(res, i - dq.pollFirst());
            }
            while (!dq.isEmpty() && pre[i] <= pre[dq.peekLast()]) {
                dq.pollLast();
            }
            dq.addLast(i);
        }
        
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}