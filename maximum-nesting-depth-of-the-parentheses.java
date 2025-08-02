class Solution {
    public int maxDepth(String s) {
        int n = s.length();
        int cnt=0,maxi=0;
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            if(ch =='('){
                cnt++;
                maxi=Math.max(maxi,cnt);
            }
            else if(ch==')') cnt--;
        }
        return maxi;
    }
}