class Solution {
    public int maxRectangleArea(int[][] points) {
        int n = points.length;
        Set<String> st = new HashSet<>();
        for (int[] i : points) st.add(i[0] + "," + i[1]);
        int maxi = -1;

        ///////////////////////
        /////////
        ///
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1],x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) continue;
                if (st.contains(x1 + "," + y2) && st.contains(x2 + "," + y1)) {
                    int min1 = Math.min(x1, x2), max1 = Math.max(x1, x2),min2 = Math.min(y1, y2), max2 = Math.max(y1, y2);
                    boolean isid = true;
                    for (int[] point : points) {
                        int cx = point[0], cy = point[1];
                        if ((cx > min1 && cx < max1 && cy > min2 && cy < max2) || ((cx == min1 || cx == max1) && (cy > min2 && cy < max2)) ||((cy == min2 || cy == max2) && (cx > min1 && cx < max1))) { 
                            isid = false;
                            break;
                        }
                    }
                    if (isid)maxi = Math.max(maxi, (max1 - min1) * (max2 - min2));
                }
            }
        }

        return maxi;
    }
}