class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        // int n = nums.length;
        // List<List<Integer>> ans = new ArrayList<>();
        // // if(target==0) return ans;
        // for(int i=0;i<n;i++){
        //     HashMap<Integer,Integer> mp = new HashMap<>();
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             for(int z=k+1;z<n;z++){
        //                 int sum =nums[i] + nums[j];
        //                 sum += nums[k];
        //                 if(mp.containsKey(target-sum)){
        //                     ArrayList<Integer> temp = new ArrayList<>();
        //                     temp.add(nums[i]);
        //                     temp.add(nums[j]);
        //                     temp.add(nums[k]);
        //                     temp.add(target-sum);
        //                     // Collections.sort(temp);
        //                     temp.sort(Integer::compareTo);
        //                     if(!ans.contains(temp))
        //                     ans.add(temp);
        //                 }
        //                 mp.put(nums[z],z);
        //             }
        //         }
        //     }
            
        // }
        // return ans;

        int n = nums.length;
        List<List<Integer>> ans  = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
            int l = j+1;
            int r = n-1;
            while(l<r){
                long sum= (long)nums[l]+nums[r]+nums[i]+nums[j];
                if(sum==target){
                    ans.add(Arrays.asList(nums[i],nums[j],nums[l],nums[r]));
                while(l<r && nums[l]==nums[l+1]) l++;
                while(l<r && nums[r]==nums[r-1]) r--;
                l++;
                r--;
                }
                else if (sum<target) l++;
                else if(sum> target) r--;
            }
            }
        }
        return ans;
    }
}