class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> {
            double diffA = (a[0] + 1) / (a[1] + 1) - a[0] / a[1];
            double diffB = (b[0] + 1) / (b[1] + 1) - b[0] / b[1];
            return Double.compare(diffB, diffA);
        });
        
        for (int[] cls : classes) {
            pq.offer(new double[]{cls[0], cls[1]});
        }
        
        for (int i = 0; i < extraStudents; i++) {
            double[] top = pq.poll();
            top[0]++;
            top[1]++;
            pq.offer(top);
        }
        
        double avgPassRatio = 0;
        while (!pq.isEmpty()) {
            double[] cls = pq.poll();
            avgPassRatio += cls[0] / cls[1];
        }
        
        return avgPassRatio / classes.length;
    }
}