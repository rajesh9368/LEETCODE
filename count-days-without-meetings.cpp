class Solution {
    public int countDays(int days, int[][] meetings) {
        int freeDays = 0;
        int lastDay = 0;
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));
        for (int[] meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            if (start > lastDay + 1) {
                freeDays += start - lastDay - 1;
            }
            lastDay = Math.max(lastDay, end);
        }
        freeDays += days - lastDay;
        return freeDays;
    }
}