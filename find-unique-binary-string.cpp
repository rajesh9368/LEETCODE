class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder sb = new StringBuilder();
        backtrack(nums, sb, 0, new ArrayList<>(Arrays.asList("0", "1")));
        Arrays.sort(nums);
        ArrayList<String> abc = new ArrayList<>(Arrays.asList(nums));
        // System.out.println(res);
        // System.out.println(abc);
        for(int i = 0; i < abc.size(); i++) {
            if(!abc.get(i).equals(res.get(i))) return res.get(i);
        }
        return res.get(abc.size()).toString();
    }
    ArrayList<String> res = new ArrayList<>();
    private void backtrack(String[] nums, StringBuilder sb, int pos, ArrayList<String> list) {
        if(sb.length() == nums.length) {
            res.add(sb.toString());
            return;
        }
        for(int i = 0; i < list.size(); i++) {
            sb.append(list.get(i));
            backtrack(nums, sb, i + 1, list);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}