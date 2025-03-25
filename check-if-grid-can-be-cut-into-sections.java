class Solution {
    public boolean checkValidCuts(int n, int[][] rectangles) {
        int m = rectangles.length;
        int[][] xIntervals = new int[m][2];
        int[][] yIntervals = new int[m][2];
        for (int i = 0; i < m; i++) {
            xIntervals[i][0] = rectangles[i][0];
            xIntervals[i][1] = rectangles[i][2];
            yIntervals[i][0] = rectangles[i][1];
            yIntervals[i][1] = rectangles[i][3];
        }
        return checkCuts(xIntervals) || checkCuts(yIntervals);
    }

    private boolean checkCuts(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int cuts = 0;
        int lastEnd = intervals[0][1];
        for (int[] interval : intervals) {
            if (lastEnd <= interval[0]) {
                cuts++;
            }
            lastEnd = Math.max(lastEnd, interval[1]);
        }
        return cuts >= 2;
    }
}