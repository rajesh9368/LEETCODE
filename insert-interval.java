class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> newint=new ArrayList<>(Arrays.asList(intervals));
        newint.add(newInterval);
        Collections.sort(newint,(a,b) -> Integer.compare(a[0],b[0]));
        int begin=newint.get(0)[0];
        int end=newint.get(0)[1];
        List<int[]> ans=new ArrayList<>();
        for(int i=1;i<newint.size();i++){
            if(newint.get(i)[0]<=end){
                end=Math.max(end,newint.get(i)[1]);
            }
            else{
                ans.add(new int[]{begin,end});
                begin=newint.get(i)[0];
                end=newint.get(i)[1];
            }
        }
        ans.add(new int[]{begin,end});
        return ans.toArray(new int[ans.size()][]);
    }
}