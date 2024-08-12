# RAISTAR

#  https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/  -->(Check if Array Is Sorted and Rotated)
class Solution {
    public boolean check(int[] nums) {
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>nums[(i+1)%nums.length]) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
} 
#  https://www.geeksforgeeks.org/problems/print-pattern3549/1  -->(Print Pattern)
***class Solution{
    public int subtract(int N,ArrayList<Integer> arr,int i){
        if(i<=0) {
            arr.add(i);
            return i;
        }
        arr.add(i);
        return subtract(N,arr,i-5);
    }
    public void addition(int N,ArrayList<Integer> arr,int i){
        if(i>N) return;
        arr.add(i);
        addition(N,arr,i+5);
    }
    public List<Integer> pattern(int N){
        // code here\
        ArrayList<Integer> arr = new ArrayList<>();
        int ans = subtract(N,arr,N);
        addition(N,arr,ans+5);
        return arr;
    }
}***

# https://www.naukri.com/code360/problems/n-triangles_6573689?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM -->(N-Triangles)
***public class Solution {
    public static void nTriangle(int n) {
        // Write your code here
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
}***

# https://www.naukri.com/code360/problems/alpha-hill_6581921?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_patternproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM  -->(Alpha Hill)
***public class Solution {
    public static void alphaHill(int n) {
        // Write your code here
        int c=65;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            for(int j=0;j<=i;j++){
                System.out.print((char)(c+j)+" ");
            }
            for(int j=i-1;j>=0;j--){
                System.out.print((char)(c+j)+" ");
            }
            System.out.println();
        }
    }
}***

#  https://www.geeksforgeeks.org/problems/print-pattern3549/1  -->(Pattern)
***class Solution {
    void printDiamond(int n) {
        // Your code here
       for (int i = 0; i < n-1; i++) {
            for (int j = 0; j<n-i-1; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j <= i; j++) {
                System.out.print("*"+" ");
            }
            System.out.println();
        }
        for (int i = n; i>=0; i--) {
            for (int j = 0; j < n-i; j++) {
                System.out.print(" ");
            }
             for (int j = 0; j<=i; j++) {
                System.out.print("*"+" ");
            }
            System.out.println();
        }
    }
}***
