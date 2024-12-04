class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        // int n = str1.length();
        // int m = str2.length();
        // for(int i=0;i<m;i++){
        //     char ch1 = str1.charAt(i);
        //     for(int j=0;j<n;j++){
        //         char ch2 = str2.charAt(j);
        //         if(ch1=='z' && ch2=='a' || Math.abs((int)ch1 - (int)ch2)<=1 ) break;
        //         else if(Math.abs((int)ch1 - (int)ch2)>1) return false;
        //     }
        // }
        // return true;

        //Approaach:-2
        int n = str1.length();
        int m = str2.length();
        int i=0,j=0;
        while(i<n && j<m){
            char ch1 = str1.charAt(i);
            char ch2 = str2.charAt(j);
            if((ch1==ch2) || (ch1+1 == ch2) || (ch1 =='z' && ch2 == 'a')) j++;
            i++;
        }
        return j==m;
    }
}