class Solution {
    public boolean divideArray(int[] nums) {
        int n = nums.length;
        if(n%2!=0) return false;
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++) mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        for(Map.Entry<Integer,Integer> i:mp.entrySet()){
            if(i.getValue()%2!=0) return false;
        }
        return true;
    }
}