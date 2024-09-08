public class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder a = new StringBuilder();
        for (char c : s.toLowerCase().toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                a.append(c);
            }
        }
        String c = a.toString();
        String r = a.reverse().toString();
        return c.equals(r);
    }
}
