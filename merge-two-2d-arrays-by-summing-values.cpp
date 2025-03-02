class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int m=nums1.length,n=nums2.length;
        int i=0,j=0;
        ArrayList<int[]>list=new ArrayList<>();
        while(i<m&&j<n){
            int arr[]=new int[2];
           if(nums1[i][0]<nums2[j][0]){
              arr[0]=nums1[i][0];
              arr[1]=nums1[i][1];
              i++;
           }else if(nums1[i][0]>nums2[j][0]){
              arr[0]=nums2[j][0];
              arr[1]=nums2[j][1];
              j++;
           }else{
            arr[0]=nums1[i][0];
            arr[1]=nums1[i][1]+nums2[j][1];
            i++;j++;
           }
           list.add(arr);
        }
        while(i<m){
            int arr[]=new int[2];
            arr[0]=nums1[i][0];
            arr[1]=nums1[i][1];
            list.add(arr);
            i++;
        }
        while(j<n){
            int arr[]=new int[2];
            arr[0]=nums2[j][0];
            arr[1]=nums2[j][1];
            list.add(arr);
            j++;
        }
        int len=list.size();
        int res[][]=new int[len][2];
        for(int k=0;k<len;k++){
            int arr[]=list.get(k);
            res[k][0]=arr[0];
            res[k][1]=arr[1];
        }
        return res;
        
    }
}