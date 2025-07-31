class Solution {
    public int majorityElement(int[] nums) {
        //tc:o(n)
        //sc:o(n)
        int n = nums.length;
        // HashMap<Integer,Integer> mp = new HashMap<>();
        // for(int i=0;i<n;i++){
        //     mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        // }
        // for(Map.Entry<Integer,Integer> i: mp.entrySet()){
        //     if(i.getValue()>n/2) return i.getKey();
        // }
        // return -1;
        //Moore voting Algorithm:- deal with the two variable
        //tc:o(n)
        //sc:o(1)
        int cnt=0,ele=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(ele==nums[i]) cnt++;
            else cnt--;
        }
        int majorcnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele) majorcnt++;
        }
        if(majorcnt>n/2) return ele;
        return -1;
    }
}