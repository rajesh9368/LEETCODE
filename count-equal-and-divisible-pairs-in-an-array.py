class Solution(object):
    def countPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt=0;
        n=len(nums)
        for i in range(0,n):
            for j in range(i+1,n):
                if nums[i]==nums[j] and (i*j)%k==0:
                    cnt=cnt+1
        return cnt