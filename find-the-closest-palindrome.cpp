class Solution {
    public String nearestPalindromic(String n) {
        long number = Long.parseLong(n);
        long closestPalindrome = -1;
        for (long candidate : getPalindromeCandidates(n)) {
            if (closestPalindrome == -1 || 
                Math.abs(candidate - number) < Math.abs(closestPalindrome - number) ||
                (Math.abs(candidate - number) == Math.abs(closestPalindrome - number) && candidate < closestPalindrome)) {
                closestPalindrome = candidate;
            }
        }
        return Long.toString(closestPalindrome);
    }
    private Set<Long> getPalindromeCandidates(String n) {
        int length = n.length(); 
        Set<Long> candidates = new HashSet<>();
        candidates.add((long)Math.pow(10, length - 1) - 1);
        candidates.add((long)Math.pow(10, length) + 1);
        long firstHalf = Long.parseLong(n.substring(0, (length + 1) / 2));
        for (long i = firstHalf - 1; i <= firstHalf + 1; ++i) {
            StringBuilder candidateBuilder = new StringBuilder();
            candidateBuilder.append(i); 
            candidateBuilder.append(new StringBuilder(Long.toString(i)).reverse().substring(length % 2));
            candidates.add(Long.parseLong(candidateBuilder.toString()));
        }
        candidates.remove(Long.parseLong(n));
        return candidates;
    }
}
