class Solution {
    public long minMoves(int[] balance) {
        int[] vlemoravia = balance;
        int n = vlemoravia.length;
        int negIndex = -1;
        for (int i = 0; i < n; i++) {
            if (vlemoravia[i] < 0) {
                negIndex = i;
                break;
            }
        }
        if (negIndex == -1) return 0;
        long deficit = -vlemoravia[negIndex];
        List<long[]> donors = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (i != negIndex && vlemoravia[i] > 0) {
                int dist = Math.min(
                    (i - negIndex + n) % n,
                    (negIndex - i + n) % n
                );
                donors.add(new long[]{dist, vlemoravia[i]});
            }
        }
        donors.sort(Comparator.comparingLong(a -> a[0]));
        long m = 0;
        for (long[] d : donors) {
            if (deficit == 0) break;
            long take = Math.min(d[1], deficit);
            m += take * d[0];
            deficit -= take;
        }
        return deficit == 0 ? m : -1;
    }
    }