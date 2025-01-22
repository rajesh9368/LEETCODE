class Solution {
    // Map approach 
    /*take two map here first fill the map1 with 1 element of the string array then after traverse the remaing string array
    and take temp map and thus fill the map and replace the existing key with the minimum value of the key*/
    public List<String> commonChars(String[] words) {
        int  n=words.length;
        String s=words[0];
        HashMap<Character,Integer> mp = new HashMap<>();
        for(int j=0;j<s.length();j++){
            if(!mp.containsKey(s.charAt(j))) mp.put(s.charAt(j),1);
            else mp.put(s.charAt(j),mp.get(s.charAt(j))+1);
        }
        for(int j=1;j<n;j++){
            HashMap<Character,Integer> hmp = new HashMap<>();
            String s1 = words[j];
            for(int i=0;i<s1.length();i++){
                if(!hmp.containsKey(s1.charAt(i))) hmp.put(s1.charAt(i),1);
                else hmp.put(s1.charAt(i),hmp.get(s1.charAt(i))+1);
            }
            for(Map.Entry<Character,Integer> i:mp.entrySet()){
                Character c = i.getKey();
                if(hmp.containsKey(c)) mp.put(c,Math.min(mp.get(c),hmp.get(c)));
                else mp.put(c,0);
            }
        }
        List<String> ans = new ArrayList<>();
        for(Map.Entry<Character,Integer> i:mp.entrySet()){
            if(i.getValue()>0){
                for (int k = 0; k < i.getValue(); k++) ans.add(String.valueOf(i.getKey()));
            }
        }
        return ans;
    }
}