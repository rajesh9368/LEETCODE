/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if(head==null || head.next==null || head.next.next==null) return new int[]{-1,-1};
       ListNode temp = head.next;
       int curpos=1;
       int prev = head.val;
       List<Integer> arr = new ArrayList<>();
       while(temp.next!=null){
        int next = temp.next.val;
        int curr = temp.val;
        if((curr>prev && curr>next)||(curr<prev && curr<next)) arr.add(curpos);
        curpos++;
        prev=curr;
        temp=temp.next;
       } 
       int n = arr.size();
       if(n<2) return new int[]{-1,-1};
       int maxi=arr.get(n-1)-arr.get(0);
       int mini = Integer.MAX_VALUE;
       for(int i=1;i<n;i++){
        mini = Math.min(mini,arr.get(i)-arr.get(i-1));
       }
       return new int[]{mini,maxi};
    }
}