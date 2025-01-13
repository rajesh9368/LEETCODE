class Solution {
    public int minimumLength(String s) {
        int n = s.length();
        HashMap<Character,Integer> mp = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(!mp.containsKey(ch)) mp.put(ch,1);
            else mp.put(ch,mp.get(ch)+1);
        }
        int cnt=0;
        for(Map.Entry<Character,Integer> i:mp.entrySet()){
            if(i.getValue()%2==1) cnt+=i.getValue()-1;
            else cnt+=i.getValue()-2;
        }
        return n-cnt;
    }
}