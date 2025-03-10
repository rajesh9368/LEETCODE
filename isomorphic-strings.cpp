class Solution {
    public boolean isIsomorphic(String s, String t) {
        int n = s.length();
        int m = t.length();
        if(n!=m) return false;
        HashMap<Character,Character> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            char sh = s .charAt(i);
            char th = t.charAt(i);
            if(mp.containsKey(sh)){
                if(mp.get(sh)!=th) return false;
            }
            if(mp.containsValue(th));
            mp.put(sh,th);
        }
        return true;
    }
}