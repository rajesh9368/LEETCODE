class Solution {
    public static int l,h,z,o;
    int[] memo;
 int MOD = 1000000007;
    // here iam taking the length of the string as it is difficult to deal with the string directly. 
    // public int operation(int length){
    //     if(length>h) return 0;
    //     int cnt = 0;
    //     if(length>=l) cnt = 1;
    //     int appendzero = operation(length+z);
    //     int appendone = operation(length+o);
    //     return (cnt+appendzero+appendone)%MOD;
    // }
    public int countGoodStrings(int low, int high, int zero, int one) {
        l=low;
        h=high;
        z=zero;
        o=one;
        // int ans = operation(0);
        // return ans;
        // recursion tle
        memo = new int[high+1];
        Arrays.fill(memo,-1);
        return operation(l,h,z,o,0);
    }
    public int operation(int l,int h,int z,int o,int i){
        if(i>h) return 0;
        if(memo[i]!=-1) return memo[i];
        memo[i]=i>=l && i<=h ? 1:0;
        memo[i] = (memo[i] + operation(l,h,z,o,i+z))%MOD;
        memo[i] = (memo[i] + operation(l,h,z,o,i+o))%MOD;
        return memo[i];
    }
}