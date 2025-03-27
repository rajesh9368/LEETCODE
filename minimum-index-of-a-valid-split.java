class Solution {

    private int majorityElement(List<Integer> nums) {
        int candidate = -1;
        int count = 0;
        for (int x : nums) {
            if (count == 0) {
                candidate = x;
            }
            count += ((x == candidate) ? 1 : -1);
        }
        return candidate;
    }

    private boolean checkDominance(int len, int cnt) {
        return cnt > (len / 2);
    }

    public int minimumIndex(List<Integer> nums) {
        int n = nums.size();
        int x = majorityElement(nums);

        int totalCount = (int)nums.stream().filter(num -> num == x).count();

        int currCount = 0;
        for (int i = 0; i < n - 1; i++) {
            int num = nums.get(i);
            if (num == x) {
                currCount++;   
            }
            int remCount = totalCount - currCount;

            int leftElement = i + 1;
            int rightElement = n - i - 1;

            if (checkDominance(leftElement, currCount) && checkDominance(rightElement, remCount))
                return i;
        }

        return -1;
    }
}