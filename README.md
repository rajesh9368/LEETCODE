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

# https://leetcode.com/problems/isomorphic-strings/description/  -->( Isomorphic Strings)
***class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()) return false;
        HashMap<Character,Character> mpp = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char sh = s.charAt(i);
            char th = t.charAt(i);
            if(mpp.containsKey(sh)){
                if(mpp.get(sh)!=th) return false;
            }
            else if(mpp.containsValue(th)) return false;
            mpp.put(sh,th);
        }
        return true;
    }
}***

# https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0  -->(Frequencies of Limited Range Array Elements)
***class Solution {
    // Function to count the frequency of all elements from 1 to N in the array.
    public static void frequencyCount(int arr[], int N, int P) {
        // do modify in the given array
        HashMap<Integer,Integer> mpp = new HashMap<>();
        for(int i=0;i<arr.length;i++){
            if(!mpp.containsKey(arr[i])) mpp.put(arr[i],1);
            else mpp.put(arr[i],mpp.get(arr[i])+1);
        }
        P=1;
        for(int i=0;i<arr.length;i++){
            if(!mpp.containsKey(P)) arr[i]=0;
            else arr[i]=mpp.get(P);
            P++;
        }
    }
}***

# https://leetcode.com/problems/rotate-image/description/  -->(Rotate Image)
***class Solution {
    public void rotate(int[][] matrix) {
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<i;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix.length/2;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[i][matrix.length-1-j];
                matrix[i][matrix.length-1-j]=temp;
            }
        }
    }
}***

# https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1  -->(LCM And GCD)
***class Solution {
    static Long gcdi(Long A,Long B){
        if(B==0) return A;
        return gcdi(B,A%B);
    }
    static Long[] lcmAndGcd(Long A , Long B) {
        // code here
       long maxi=Math.max(A,B);
       long gcd = gcdi(A,B);
       long lcm=0;

       lcm=(A*B)/gcd;
       return new Long[]{lcm,gcd};
    }
}***
