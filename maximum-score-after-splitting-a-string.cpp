class Solution {
    public int maxScore(String s) {
        int n = s.length();
        int maxi=0,sum=0;
        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='1') cnt1++;
        }
        for(int i=0;i<n-1;i++){
            if(s.charAt(i)=='0') cnt0++;
            else cnt1--;
            sum=cnt0+cnt1;
            maxi=Math.max(maxi,sum);
        }
        return maxi;
    }
}