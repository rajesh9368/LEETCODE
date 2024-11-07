class Solution {
    public int largestCombination(int[] candidates) {
        int max = 0;
        int num[] = new int[25];
        for(int i : candidates) {
            calBitCount(i, num);
        }
        for(int i : num) {
            max = max < i ? i : max;
        }
        return max;
    }
    private void calBitCount(int num, int a[]) {
        int j = 24;
        while(num > 0) {
            a[j] += (num & 1);
            j--;
            num >>= 1;
        }
    }
}