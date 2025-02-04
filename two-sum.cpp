class Solution {
    public int[] twoSum(int[] nums, int target) {
        //Brute Approach 
        //tc:o(n^2)
        //sc:o(1)
        int n = nums.length;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int sum=nums[i]+nums[j];
        //         if(sum==target) return new int[]{i,j};
        //     }
        // }
        // return new int[]{0};

        // optimize using map
        //tc:o(n)
        //sc:o(n)
        // HashMap<Integer,Integer> mp = new HashMap<>();
        // for(int i=0;i<n;i++){
        //     if(mp.containsKey(target-nums[i])) return new int[]{i,mp.get(target-nums[i])};
        //     mp.put(nums[i],i);
        // }
        // return new int[]{0};

        //using two pointer approach
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++) mp.put(nums[i],i);
        Arrays.sort(nums);
        int fidx=0,lidx=0;
        int i=0,j=n-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==target){
                fidx=nums[i];
                lidx=nums[j];
                return new int[]{mp.get(fidx),mp.get(lidx)};
            }
            else if(sum<target) i++;
            else j--;
        }
        return new int[]{0};
    }
}