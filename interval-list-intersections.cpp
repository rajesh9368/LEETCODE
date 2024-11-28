class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> intersect = new ArrayList<>();
        int i=0,j=0;
        while(i<firstList.length && j<secondList.length){
            int s = Math.max(firstList[i][0],secondList[j][0]);
            int e = Math.min(firstList[i][1],secondList[j][1]);
            if(s<=e) intersect.add(new int[]{s,e});
            if(firstList[i][1]<=secondList[j][1]) i++;
            else j++;
        }
        return  intersect.toArray(new int[0][]);
    }
}