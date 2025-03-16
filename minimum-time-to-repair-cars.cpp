class Solution {
    public long repairCars(int[] ranks, int cars) {
        long left=1;
        int r=ranks[0];
        for(int i=1;i<ranks.length;i++){
            r=Math.max(r,ranks[i]);
        }
        long right=(long) r*cars*cars;
        while(right>left){
            long mid=left+(right-left)/2;
            if(ispossible(ranks,cars,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return right;
    }
    public static boolean ispossible(int[] ranks, int cars, long mid){
        int car_rep=0;
        for(int i:ranks){
            int n=(int) Math.sqrt(mid/i);
            car_rep+=n;
            if(car_rep>=cars){
                return true;
            }
        }
        return false;
    }
}