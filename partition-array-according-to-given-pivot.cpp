class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int[] res = new int[nums.length];
        List<Integer>less=new ArrayList<>();
        List<Integer>high=new ArrayList<>();
        List<Integer>pvt = new ArrayList<>();
        for(int n: nums)
        {
            if(n==pivot)
            {
                pvt.add(n);
            }
            else if(n<pivot)
            {
                less.add(n);
            }
            else
            {
                high.add(n);
            }
        }
        int ind=0;
        int size=0;
        while(size<less.size())
        {
            nums[ind]=less.get(size);
            ind++;
            size++;
        }
        size=0;
        while(size<pvt.size())
        {
            nums[ind]=pvt.get(size);
            ind++;
            size++;
        }
        size=0;
        while(size<high.size())
        {
            nums[ind]=high.get(size);
            ind++;
            size++;
        }
        return nums;
    }
}