class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxi=0;
        int l=0,r=0;
        HashSet<Character> st = new HashSet<>();
        while(r<n){
            if(!st.contains(s.charAt(r))){
                st.add(s.charAt(r));
                maxi=Math.max(maxi,r-l+1);
                r++;
            }
            else{
                st.remove(s.charAt(l));
                l++;
            }
        }
        return maxi;
    }
}