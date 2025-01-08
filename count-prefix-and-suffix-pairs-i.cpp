class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int count = 0;
        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (check(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }

    public boolean check(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2) {
            return false;
        }
        for (int i = 0; i < len1; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                return false;
            }
        }
        for (int i = 1; i <= len1; i++) {
            if (s1.charAt(len1 - i) != s2.charAt(len2 - i)) {
                return false;
            }
        }
        return true;
    }
}
