class Solution {
    public int[] resultsArray(int[][] queries, int k) {
         int n = queries.length;
        int[] res = new int[n];
        PriorityQueue<Integer> maxH = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int d = Math.abs(x) + Math.abs(y);
            maxH.add(d);
            if (maxH.size() > k) maxH.poll();        
            if (maxH.size() == k) res[i] = maxH.peek();
            else res[i] = -1; 
        }
        return res;
    }
}