class Solution {
    public int getLargestOutlier(int[] nums) {
        int  total=0;
        int n = nums.length;
        for(int i=0;i<n;i++) total+=nums[i];
        TreeMap<Integer,Integer> mp = new TreeMap<>();
        for(int i=0;i<n;i++) mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        int res = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            if((total-nums[i])%2==0){
                int t = (total-nums[i])/2;
                if (mp.get(nums[i]) == 1)  mp.remove(nums[i]);
                else  mp.put(nums[i], mp.get(nums[i]) - 1);
                if (mp.containsKey(t)) {
                    res = Math.max(res, nums[i]);
                }
                mp.put(nums[i],mp.getOrDefault(nums[i], 0) + 1);
            }
        }
          return res == Integer.MIN_VALUE ? -1 : res;
    }
}