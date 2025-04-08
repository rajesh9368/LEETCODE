class Solution {
    public int findDuplicate(int[] nums) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;i++) mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        for(Map.Entry<Integer,Integer> i:mp.entrySet()){
            if(i.getValue()>1) return i.getKey();
        }
        return -1;
    }
}