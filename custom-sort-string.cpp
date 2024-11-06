class Solution {
    public String customSortString(String y, String x) {
        // Write your code here.
        StringBuilder ans = new StringBuilder();
        HashSet<Character> st = new HashSet<>();
        int n = x.length();
        int m = y.length();
        if(m==0) return x;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char xh = x.charAt(j);
                char yh = y.charAt(i);
                if(xh==yh){
                    ans.append(yh);
                }
            }
            st.add(y.charAt(i));
        }
        for(int i=0;i<n;i++){
            if(!st.contains(x.charAt(i))) ans.append(x.charAt(i));
        }
        return ans.toString();
    }
}