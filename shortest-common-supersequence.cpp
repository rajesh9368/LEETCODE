class Solution {
    public String operation(String str1,String str2,int n,int m){
        int[][] dp=new int[n+1][m+1];
        for(int k=1;k<=n;k++){
            for(int l=1;l<=m;l++){
                if(str1.charAt(k-1)==str2.charAt(l-1)) dp[k][l]=1+dp[k-1][l-1];
                else dp[k][l]=0+Math.max(dp[k-1][l],dp[k][l-1]);
            }
        }
        int rus=dp[n][m];
        int len = n+m-rus;
        String ans="";
        int i=n,j=m;
       

        while(i>0 && j>0&& len>=0){
            if(str1.charAt(i-1)==str2.charAt(j-1)){
                ans+=str1.charAt(i-1);
                len--;
                i--;
                j--;
            }
           else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1.charAt(i-1);
                len--;
                i--;
            }
            else if(dp[i][j-1]>=dp[i-1][j]){
                ans+=str2.charAt(j-1);
                len--;
                j--;
            }
            System.out.println(i+" "+j+" "+len);
            // cout<<i<<" "<<j<<" "<<len<<endl;
        }
        System.out.println("hello");
        while(i>0 && len>=0){
            ans+=str1.charAt(i-1);
            len--;
            i--;
        }
        while(j>0 && len>=0){
            ans+=str2.charAt(j-1);
            len--;
            j--;
        }
        String res = new StringBuilder(ans).reverse().toString();
        return res;
        }
    public String shortestCommonSupersequence(String str1, String str2) {
        int n = str1.length();
        int m = str2.length();
        return operation(str1,str2,n,m);
    }
}