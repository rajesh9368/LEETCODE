class Solution {
    public int maxDifference(String s) {
        int n = s.length();
        HashMap<Character,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            mp.put(ch,mp.getOrDefault(ch,0)+1);
        }
        int evenmax = Integer.MAX_VALUE;
        int oddmax = 0;
        for(Map.Entry<Character,Integer> i:mp.entrySet()){
            int freq = i.getValue();
            if(freq%2==0) evenmax = Math.min(freq,evenmax);
            else oddmax = Math.max(oddmax,freq);
        } 
        return oddmax-evenmax;
    }
}