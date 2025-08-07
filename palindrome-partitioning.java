class Solution {
    public boolean isPalindrome(String s,int start,int end){
        while(start<=end){
            if(s.charAt(start)!=s.charAt(end)) return false;
            start++;
            end--;
        }
        return true;
    }
    public void operation(int idx,String s,List<List<String>> ans,ArrayList<String> res){
        if(idx==s.length()){
            ans.add(new ArrayList<>(res));
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s,idx,i)){
                res.add(s.substring(idx,i+1));
                operation(i+1,s,ans,res);
                res.remove(res.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        int n = s.length();
       List<List<String>> ans = new ArrayList<>();
       ArrayList<String> res = new ArrayList<>();
       operation(0,s,ans,res);
       return ans;
    }
}