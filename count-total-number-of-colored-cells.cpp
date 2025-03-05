class Solution {
    public long coloredCells(int n) {
        long cnt=1;
        int cellstoadd=4;
        while(--n!=0){
            cnt+=cellstoadd;
            cellstoadd+=4;
        }
        return cnt;
    }
}