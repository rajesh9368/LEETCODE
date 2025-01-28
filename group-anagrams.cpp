class Solution {
     private boolean areAnagrams(String word1, String word2) {
        if (word1.length() != word2.length())
            return false;
        
        char[] chars1 = word1.toCharArray();
        char[] chars2 = word2.toCharArray();
        
        Arrays.sort(chars1);
        Arrays.sort(chars2);
        
        return Arrays.equals(chars1, chars2);
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<>();
        boolean[] visited = new boolean[strs.length];

        for (int i = 0; i < strs.length; i++) {
            if (!visited[i]) {
                List<String> group = new ArrayList<>();
                group.add(strs[i]);
                for (int j = i + 1; j < strs.length; j++) {
                    if (!visited[j] && areAnagrams(strs[i], strs[j])) {
                        group.add(strs[j]);
                        visited[j] = true;
                    }
                }
                result.add(group);
                visited[i] = true;
            }
        }

        return result;
}
}