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
***class Solution{
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


# https://leetcode.com/problems/valid-anagram/description/  -->(Valid Anagram)
***class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character,Integer> mpp1 = new HashMap<>();
        HashMap<Character,Integer> mpp2 = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char sh = s.charAt(i);
            if(mpp1.containsKey(sh)) mpp1.put(sh,mpp1.get(sh)+1);
            else mpp1.put(sh,1);
        }
        for(int i=0;i<t.length();i++){
            char th = t.charAt(i);
            if(mpp2.containsKey(th)) mpp2.put(th,mpp2.get(th)+1);
            else mpp2.put(th,1);
        }
        if(mpp1.equals(mpp2)) return true;
        return false;
    }
}***

# https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1  -->(Minimum Platforms)
***class Solution
{
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static int findPlatform(int arr[], int dep[], int n)
    {
        // add your code here
        int plat=0,track=0;
        Arrays.sort(arr);
        Arrays.sort(dep);
        int i=0,j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                track++;
                i++;
            }
            else{
                track--;
                j++;
            }
            plat=Math.max(plat,track);
        }
        return plat;
    }
}***


#  https://www.geeksforgeeks.org/problems/node-at-a-given-index-in-linked-list/1  -->(Node at a given index in linked list)
***class Solution {
    public int GetNth(Node head, int index) {
        // Code here
        int i=index;
        while(head!=null){
        if(i==1) return head.data;
            head=head.next;
            i--;
        }
        return -1;
    }
}***

# https://leetcode.com/problems/delete-node-in-a-linked-list/description/  -->( Delete Node in a Linked List)
***class Solution {
    public void deleteNode(ListNode node) {
        node.val=node.next.val;
        node.next=node.next.next;
    }
}***

# https://leetcode.com/problems/two-sum/description/  -->(Two Sum)
***class Solution {
    public int[] twoSum(int[] arr, int target) {
        int[] ans = new int[2];
        for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
                if(target==arr[i]+arr[j]){
                ans[0]=i;
                ans[1]=j;
                }
            }
        }
        return ans;
    }
}***

# 
