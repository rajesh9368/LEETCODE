class Solution {
    public int buttonWithLongestTime(int[][] events) {
        int n=events.length,res = events[0][0],eve=events[0][1];
        int i=1;
        while(i<n){
           if(events[i][1]-events[i-1][1]>eve){ eve=events[i][1]-events[i-1][1];
               res=events[i][0];
           } 
            else if(events[i][1]-events[i-1][1]==eve) res = Math.min(res,events[i][0]);
            i++;
        }
        return res;
    }
}