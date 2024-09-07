class Solution {
    public boolean operation(String s){
        int i=0;
        while(i<=s.length()/2){
            if(s.charAt(i)!=s.charAt(s.length()-i-1)) return false;
            i++;
        }
        return true;
    }
    public String longestPalindrome(String s) {
        int n = s.length();
        if(n<=1) return s;
        int maxlen=1;
        String str = s.substring(0,1);
        for(int i=0;i<n;i++){
            for(int j=i+maxlen;j<=n;j++){
                if(j-i>maxlen && operation(s.substring(i,j))){
                maxlen = j-i;
                str = s.substring(i,j);
                }
            }
        }
        return str;
    }
}