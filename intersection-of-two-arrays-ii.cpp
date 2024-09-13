import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] count = new int[1001];  
        List<Integer> a = new ArrayList<>();  
        for (int num : nums1) count[num]++;
        for (int num : nums2) {
            if (count[num] > 0) {
                a.add(num);
                count[num]--;
            }
        }
        int[] intersect = new int[a.size()];
        for (int i = 0; i < a.size(); i++)  intersect[i] = a.get(i);
        return intersect;
    }
}