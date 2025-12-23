class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events,(e1,e2)->e1[1]-e2[1]);
        TreeMap<Integer,Integer> dp = new TreeMap<>();
        int max = 0, max2 = 0;
        for(int i=0; i<events.length; i++){
            max=Math.max(max,events[i][2]);
            Map.Entry<Integer,Integer> e = dp.lowerEntry(events[i][0]);
            dp.put(events[i][1],max);
            if(e != null){
                max2=Math.max(max2,e.getValue()+events[i][2]);
            }
        }
        return Math.max(max,max2);
    }
}