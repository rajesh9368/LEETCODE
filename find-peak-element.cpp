class Solution {
    public int findPeakElement(int[] a) {
        if(a.length==1) return ;
        int index=-1;
        int ans = Integer.MAX_VALUE;
    //    Arrays.sort(a);
       for(int i=0;i<a.length;i++){
        ans=Math.max(ans,a[i]);
        index=i;
       }
       return index-1;
       } 
}