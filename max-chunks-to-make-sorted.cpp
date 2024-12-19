class Solution {
    public int maxChunksToSorted(int[] arr) {
        int ans = 0;
        int n = arr.length;
            int[] prefix = new int[n];
            prefix[0] = arr[0];
            for(int i=1;i<n;i++){
                prefix[i] = Math.max(prefix[i-1],arr[i]);
            }
            for(int i=0;i<n;i++){
                if(prefix[i] == i) {
                    ans++;
                }
            }
            return ans;
    }
}