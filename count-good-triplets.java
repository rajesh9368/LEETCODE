class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < arr.length - 2; i++) {
            for (int j = i + 1; j < arr.length - 1; j++) {
                int a1 = Math.abs(arr[i] - arr[j]);
                if (a1 <= a) {
                    for (int k = j + 1; k < arr.length; k++) {
                        int b1 = Math.abs(arr[j] - arr[k]);
                        int c1 = Math.abs(arr[i] - arr[k]);
                        if (b1 <= b && c1 <= c) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
}