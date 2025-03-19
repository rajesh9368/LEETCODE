class Solution {
    //n!
    public void operation(int[] nums,int i,ArrayList<Integer> temp,List<List<Integer>> ans,boolean[] visited){
        if(temp.size()==nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int j=0;j<nums.length;j++){
            if(visited[j]==false){
                temp.add(nums[j]);
                visited[j] = true;
                operation(nums,j+1,temp,ans,visited);
                temp.remove(temp.size()-1);
                visited[j]=false;
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        ArrayList<Integer> temp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        boolean[] visited = new boolean[nums.length]; // will treat like map as to track whether contains element or not
        operation(nums,0,temp,ans,visited);
        return ans;
    }
}