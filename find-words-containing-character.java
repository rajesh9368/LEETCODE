class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> al = new ArrayList<>();
        int count = 0;
        for(String ch : words)
        {
            if(ch.contains(String.valueOf(x)))
                al.add(count);
            count++;
        }

        return al;
        
    }
}