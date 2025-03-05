import java.util.*;

class Solution {
    public int singleNumber(int[] arr) {
        int n = arr.length;
        int xor=0;
        for(int i=0;i<n;i++){
            xor=xor^arr[i];
        }
        return xor;
    }
}
