import java.util.*;

class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0, sum2 = 0;
        int x1 = 0, x2 = 0;

        for (int i : nums1) {
            sum1 += i;
            if (i == 0) x1++;
        }

        for (int i : nums2) {
            sum2 += i;
            if (i == 0) x2++;
        }

        long diff = Math.abs(sum1 - sum2);

        if (sum1 == sum2 && x1 == x2) return sum1 + x1;

        if ((x1==0 && diff < x2) || (x2==0 && diff < x1) || (sum1 < sum2 && x1 == 0) || (sum1 > sum2 && x2 == 0) || (sum1 == sum2 && (x1 == 0 || x2 == 0)))
            return -1;

        if (sum1 == sum2) {
            return Math.max(sum1 + x1, sum2 + x2);
        }

        return Math.max(sum1 + x1, sum2 + x2);
    }
}