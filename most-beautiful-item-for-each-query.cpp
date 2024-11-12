// class Solution {
//     public int[] maximumBeauty(int[][] items, int[] queries) {
//         int n = queries.length;
//         int m = items.length;
//         int[] ans = new int[n];
//         for(int i=0;i<n;i++){
//             int profit=0;
//             for(int j=0;j<m;j++){
//                 if(items[j][0] <= queries[i]) {
//                     profit = Math.max(profit,items[j][1]);
//                 }
//             }
//             ans[i] = profit;
//         }
//         return ans;
//     }
// }  TLE

class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> a[0] - b[0]);

        int currMax = Integer.MIN_VALUE;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        tm.put(0, 0);
        for (int[] item : items) {
            currMax = Math.max(currMax, item[1]);
            tm.put(item[0], currMax);
        }

        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            res[i] = tm.floorEntry(queries[i]).getValue();
        }
        return res;
    }
}