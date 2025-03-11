class Solution {
    public int numberOfSubstrings(String s) {
        char[] ch=s.toCharArray();
        int[] abc=new int[3];
        for(int i=0;i<abc.length;i++){
            abc[i]=-1;
        }
        int c=0,r=0;
        while(r<ch.length){
            abc[ch[r]-'a']=r;
            int min=Integer.MAX_VALUE;
            for(int i=0;i<3;i++){
                min=Math.min(min,abc[i]);
            }
            c+=(min+1);
            r++;
        }
        return c;
    }
}