class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length(),m = t.length();
        if(n!=m) return false;
        HashMap<Character,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            char sh = s.charAt(i),th = t.charAt(i);
            mp.put(sh,mp.getOrDefault(sh,0)+1);
            mp.put(th,mp.getOrDefault(th,0)-1);
        }
        for(Map.Entry<Character,Integer> i:mp.entrySet()){
            if(i.getValue()>0) return false;
        }
        return true;
    }
}