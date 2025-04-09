class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        int cnt=1;
        int maxi=0;
        HashSet<Integer> st = new HashSet<>();
        for(int i:nums) st.add(i);
        for(int i: st){
            if(!st.contains(i-1)){
                int start = i;
                cnt=1;
                while(st.contains(start+1)){
                    cnt++;
                    start++;
                }
            }
            maxi = Math.max(maxi,cnt);
        }
        return maxi;
    }
}