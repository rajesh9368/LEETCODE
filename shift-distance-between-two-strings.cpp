class Solution {
    public long shiftDistance(String s, String t, int[] nextCost, int[] previousCost) {
        int n = s.length();
        long tc = 0;
        for (int i = 0; i < n; ++i) {
            int st = s.charAt(i) - 'a';
            int ta = t.charAt(i) - 'a';
            int cs = (ta - st + 26) % 26;
            long cc = 0;
            for (int j = 0; j < cs; ++j) {
                cc += nextCost[(st + j) % 26];
            }
            int ccs = (st - ta + 26) % 26;long ccc = 0;
            for (int j = 0; j < ccs; ++j) {
                ccc += previousCost[(st - j + 26) % 26];
            }   
            tc += Math.min(cc, ccc);
        }
        return tc;
    }
}
