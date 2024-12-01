class Solution {
    public int smallestNumber(int n) {
        int ans=n;
        while((ans&(ans+1))!=0) ans++;
        return ans;
    }
}
