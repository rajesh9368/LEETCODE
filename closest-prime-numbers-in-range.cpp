class Solution {
    int[] ans = {-1, -1};
    int temp = Integer.MAX_VALUE;
    int prev = 0;
    public void calculatePair(int number) {
        if(number <= 1) return;
        for(int i = 2; i <= Math.sqrt(number); i++) {
            if(number % i == 0) return;
        }
        // At this point the number is prime.
        if(number - prev < temp && prev != 0){
            temp = number - prev;
            ans[0] = prev;
            ans[1] = number;
        }
        prev = number;
    }

    public int[] closestPrimes(int left, int right) {
        for(int i = left; i <= right; i++) {
            calculatePair(i);
            // The diff is <=2 which means it is as close as it gets.
            if(temp <= 2) return ans; 
        }
        return ans;
    }
}