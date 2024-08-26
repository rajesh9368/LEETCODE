class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> st = new HashSet<Character>();
        int i=0,j=0,maxlen=0;
        while(i<s.length() && j<s.length()){
            if(!st.contains(s.charAt(j))){
                st.add(s.charAt(j));
                j++;
                maxlen=Math.max(maxlen,j-i);
            }
            else{
                st.remove(s.charAt(i));
                i++;
            }
        }
        return maxlen;
    }
}