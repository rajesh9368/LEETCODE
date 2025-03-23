class Solution {
    public int maxContainers(int n, int w, int maxWeight) {
       int num=maxWeight/w;
       while(num>n*n){
        num--;
       }
       return num;
    }
}