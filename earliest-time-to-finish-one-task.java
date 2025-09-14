class Solution {
    public int earliestTime(int[][] tasks) {
        int n = tasks.length,mini=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            mini = Math.min(mini,tasks[i][0] + tasks[i][1]);
        }
        return mini;
    }
}