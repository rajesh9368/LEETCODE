class Solution {
    public String removeOuterParentheses(String s) {
        int n = s.length();
        int cnt=0;
        StringBuilder ans = new StringBuilder();
        for(int i=0;i<n;i++){
            if(s.charAt(i)==')') cnt--;
            if(cnt!=0) ans.append(s.charAt(i));
            if(s.charAt(i)=='(') cnt++;
        }
        return ans.toString();
    }
}