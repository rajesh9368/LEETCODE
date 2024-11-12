class Solution {
    public int minMoves(int[] arr) {
        int n = arr.length;
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     int count=0;
        //     for(int j=0;j<n;j++){
        //         if(i==j) continue;
        //         if(arr[i]==arr[j]) count++;
        //     }
        //     maxi=Math.max(maxi,count);
        // }
        // return n-maxi;
        // HashMap<Integer,Integer> mp = new HashMap<>();
        // for(int i=0;i<n;i++){
        //     if(!mp.containsKey(arr[i])) mp.put(arr[i],1);
        //     else mp.put(arr[i],mp.get(arr[i])+1);
        // }
        // int maxi = 0;
        // for(Map.Entry<Integer,Integer> i: mp.entrySet()){
        //     if(i.getValue()>maxi) maxi = i.getValue();
        // }
        // return n-maxi;
        int mini = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            mini = Math.min(mini,arr[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=arr[i]-mini;
        }
        return cnt;
    }
}