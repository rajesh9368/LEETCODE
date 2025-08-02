class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n = s.length(),m=t.length();
        HashMap<Character,Character> mp = new HashMap<>();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            char sh = s.charAt(i),th = t.charAt(i);
            if(mp.containsKey(sh)){
                if(mp.get(sh)!=th) return false;
            }
            else if(mp.containsValue(th)) return false;
            mp.put(sh,th);
        }
        return true;
    }
}