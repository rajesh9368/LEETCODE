class Solution {
      //
     public long calculateScore(String s) {
        Map<Character,TreeSet<Integer>> mp = new HashMap<>();
        long sc = 0;
        for (int i = 0; i < s.length(); i++) {
            char cc = s.charAt(i),mm = op(cc);
            if (mp.containsKey(mm) && !mp.get(mm).isEmpty()) {
                int j = mp.get(mm).pollFirst();sc+=(i - j);
            } else {
                mp.putIfAbsent(cc, new TreeSet<>(Comparator.reverseOrder())); mp.get(cc).add(i);
            }
        }
        return sc;
    }
    //
       char op(char c) {
        int t = c - 'a';
        return (char) ('z' - t);
    }
    }