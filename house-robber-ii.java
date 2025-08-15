class Solution {
    public int operation(ArrayList<Integer> temp3){
         int prev = temp3.get(0);
         int prev2 = 0;
        for(int i=1;i<temp3.size();i++){
            int take = temp3.get(i);
            if(i>1) take += prev2;
            int nottake = prev;
            int curr = Math.max(take,nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    public int rob(int[] arr) {
          if (arr.length == 1) return arr[0];
       ArrayList<Integer> temp1 = new ArrayList<>();
       ArrayList<Integer> temp2 = new ArrayList<>();
       for(int i=0;i<arr.length;i++){
        if(i!=0) temp1.add(arr[i]);
        if(i!=arr.length-1) temp2.add(arr[i]);
       }
       return Math.max(operation(temp1),operation(temp2));
    }
}