class Solution {
    public int maximumLength(String s) {
     HashMap<String, Integer> mp = new HashMap<>();
        int i = 1;
        int start = 0, end = -1;
        while (i <= s.length()) {
            if (i < s.length() && s.charAt(i) == s.charAt(start)) {
                i++;
            } else {
                end = i - 1;
                char ch = s.charAt(start);
                int k = end - start + 1;
                StringBuilder temp = new StringBuilder();
                for (int j = 0; j < end - start + 1; j++) {
                    temp.append(ch);
                    mp.put(temp.toString(), mp.getOrDefault(temp.toString(), 0) + k);
                    k--;
                }
                start = i;
                i++;
            }
        }

        int ans = -1;
        for (var entry : mp.entrySet()) {
            if (entry.getValue() >= 3) {
                int k = entry.getKey().length();
                ans = Math.max(ans, k);
            }
        }
        return ans;
    }
}