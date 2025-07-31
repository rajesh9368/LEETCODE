class Solution {
    public void merge(int[] arr, int low, int mid, int high) {
        ArrayList<Integer> temp = new ArrayList<>();
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] < arr[right]) {
                temp.add(arr[left++]);
            } else {
                temp.add(arr[right++]);
            }
        }
        while (left <= mid) temp.add(arr[left++]);
        while (right <= high) temp.add(arr[right++]);
        for (int i = low; i <= high; i++) {
            arr[i] = temp.get(i - low);
        }
    }
    public int countpair(int[] nums, int low, int mid, int high) {
        int right = mid + 1, cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > 2L * nums[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    public int mergesort(int[] nums, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergesort(nums, low, mid);
        cnt += mergesort(nums, mid + 1, high);
        cnt += countpair(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

    public int reversePairs(int[] nums) {
        return mergesort(nums, 0, nums.length - 1);
    }
}
