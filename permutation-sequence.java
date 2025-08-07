class Solution {
    public void operation(int[] nums, List<List<Integer>> ans, ArrayList<Integer> temp, boolean[] map) {
        if (temp.size() == nums.length) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!map[i]) {
                map[i] = true;
                temp.add(nums[i]);
                operation(nums, ans, temp, map);
                temp.remove(temp.size() - 1);
                map[i] = false;
            }
        }
    }
    public String getPermutation(int n, int k) {
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = i + 1;
        List<List<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        boolean[] map = new boolean[nums.length];
        operation(nums, ans, temp, map);
        if (k > ans.size()) return "0"; 
        List<Integer> kth = ans.get(k - 1);
        StringBuilder sb = new StringBuilder();
        for (int num : kth) sb.append(num);

        return sb.toString();
    }
}
