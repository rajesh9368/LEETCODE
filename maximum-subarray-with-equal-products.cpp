class Solution {
        static int g1(int a, int b) {
        if (b == 0) return a;
        return g1(b, a % b);
    }
   public int maxLength(int[] nums) {
        int ans = 0,n = nums.length;
        for (int i = 0; i < n; i++) {
        int p= 1,currg= nums[i],currl= nums[i];
for (int j = i; j < n; j++) {
                p *= nums[j];
    currl=l2(currl, nums[j]);
                currg=g1(currg, nums[j]);
                if (p == currl * currg) ans= Math.max(ans, j - i + 1);
            }
        }
        return ans;
    }
      static int l2(int a, int b) {
        return (a / g1(a, b)) * b;
    }

}