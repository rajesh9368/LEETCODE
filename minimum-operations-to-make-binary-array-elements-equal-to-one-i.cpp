class Solution {
    public int minOperations(int[] arr) {
        int n = arr.length;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(i+2>=n) return -1;
                for(int j=i;j<=i+2;j++){
                    if(arr[j]==0) arr[j]=1;
                    else arr[j]=0;
                }
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0) cnt=-1;
        }
        return cnt;
    }
}