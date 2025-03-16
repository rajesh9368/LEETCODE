class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        int maxi=0,cnt=0;
        HashSet<Integer> st = new HashSet<>();
        for(int i=0;i<n;i++) st.add(nums[i]);
        for(int i:st){
            if(!st.contains(i-1)){
                int starting=i;
                cnt=1;
                while(st.contains(starting+1)){
                    cnt++;
                    starting++;
                }
            }
            maxi=Math.max(maxi,cnt);
        }
        return maxi;
    }
}