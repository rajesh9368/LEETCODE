class Solution {
    public int minBitFlips(int start, int goal) {
        int cnt=0;
        int xor = start^goal;
        while(xor!=0){
            cnt+=xor&1;
            xor>>=1;
        }
        return cnt;
    }
}