class Solution {
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder();
        int i=0,n=s.length();
        while(i<n){
        while(i<n && s.charAt(i)==' ') i++;
        if (i == n) break; 
        int j=i+1;
        while(j<n && s.charAt(j)!=' ') j++;
        String sub = s.substring(i,j);
        if(ans.length()==0) ans.append(sub);
        else ans.insert(0,sub+' '); 
        i=j+1;
        }
        return ans.toString();
    }
}