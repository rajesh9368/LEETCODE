class Solution {
    public int[] twoSum(int[] arr, int target) {
        // can also be solved using two pointer only if we have to find that pair not to find the indexes
        //tc:o(n^2)
        //sc:o(1)
        int n = arr.length;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[i]+arr[j]==target){
        //             return new int[]{i,j};
        //         }
        //     }
        // }
        // return new int[]{-1,-1};
        //tc:o(n)
        //sc:o(n)
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            if(mp.containsKey(target-arr[i])) return new int[]{mp.get(target-arr[i]),i};
            mp.put(arr[i],i);
        }
        return new int[]{-1,-1};
    }
}