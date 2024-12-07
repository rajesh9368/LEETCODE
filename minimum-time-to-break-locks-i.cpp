class Solution {
    public int findMinimumTime(List<Integer> strengthInput, int KInput) {
        this.n = strengthInput.size();this.strength = strengthInput.stream().mapToInt(i -> i).toArray();
        this.K = KInput;
        this.arr = new long[1 << n][100];
        for (long[] r : arr) Arrays.fill(r, -1);
        long mini = operation(0, 1);
        return (mini <= 1e12) ? (int) mini : -1;
    }
     int n,K; 
    long[][] arr; 
    int[] strength; 

    
    private long operation(int opd, int y) {
        if (opd== (1 << n) - 1) 
                                    return 0;
        if (arr[opd][y] != -1) 
            return arr[opd][y];
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if ((opd & (1 << i)) == 0) { 
                long ty = (long) Math.ceil((double) strength[i] /y);
                long tt = ty + operation(opd|(1 << i), y + K);
                ans = Math.min(ans, tt);
            }
        }
        return arr[opd][y] = ans;
    }
}
