class Solution {
    public static final int mod = 1000000007;


    // 

    
    public long op1(long x, long y) {
        long result = 1; x = x%mod;
        while (y > 0) {
            if ((y & 1) == 1) result = (result * x)%mod;
            x = (x * x)%mod;
            y >>= 1;
        }
        return result;
    }
  
   
    public int countGoodArrays(int n, int m, int k) {
        if (k >= n)return 0;
        long kp = op2(n - 1, k),r = op1(m - 1, n - k - 1);
        long a = (kp * m)%mod;
        a=(a*r)%mod;return (int)a;
    }
     private long op2(long n, long r) {
        if (r > n) return 0;
        if (r == 0)return 1;
        long nu=1,de=1; 
        for (long i=0;i<r;i++) {
            nu =(nu*(n - i))%mod;
            de=(de*(i+1))%mod;
        }
        return (nu*op3(de))%mod;
    }

//
      private long op3(long a) {
        return op1(a, mod-2);
    }
}
