class Solution {
    public int beautySum(String s) {
        int n = s.length(),sum=0;
        for(int i=0;i<n;i++){
            HashMap<Character,Integer> mp = new HashMap<>();
            for(int j=i;j<n;j++){
                mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0)+1);
                int maxi = Integer.MIN_VALUE,mini = Integer.MAX_VALUE;
                for(int k:mp.values()){
                    maxi=Math.max(maxi,k);
                    mini = Math.min(mini,k);
                }
                    sum+=maxi-mini;
            }
        }
        return sum;
    }
}