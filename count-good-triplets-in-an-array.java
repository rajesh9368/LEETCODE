import java.util.*;

class Solution {
    
    static class FenwickTree {
        int[] bit;
        int n;

        FenwickTree(int n) {
            this.n = n;
            bit = new int[n + 2];
        }

        void update(int index, int delta) {
            index++;
            while (index <= n + 1) {
                bit[index] += delta;
                index += index & -index;
            }
        }

        int query(int index) {
            index++;
            int sum = 0;
            while (index > 0) {
                sum += bit[index];
                index -= index & -index;
            }
            return sum;
        }
    }

    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] posInNums2 = new int[n];
        
        for (int i = 0; i < n; i++) {
            posInNums2[nums2[i]] = i;
        }

        int[] transformed = new int[n];
        for (int i = 0; i < n; i++) {
            transformed[i] = posInNums2[nums1[i]];
        }

        FenwickTree leftTree = new FenwickTree(n);
        FenwickTree rightTree = new FenwickTree(n);

        for (int val : transformed) {
            rightTree.update(val, 1);
        }

        long count = 0;
        for (int i = 0; i < n; i++) {
            int mid = transformed[i];
            rightTree.update(mid, -1);

            int leftCount = leftTree.query(mid - 1);
            int rightCount = rightTree.query(n - 1) - rightTree.query(mid);

            count += (long) leftCount * rightCount;
            leftTree.update(mid, 1);
        }

        return count;
    }
}