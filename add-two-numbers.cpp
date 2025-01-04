class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
             ListNode dummy = new ListNode();
             ListNode res = dummy;
             int c=0,total=0;
             while(l1!=null || l2!=null || c!=0){
                total=c;
                if(l1!=null){
                    total+=l1.val;
                    l1=l1.next;
                }
                if(l2!=null){
                    total+=l2.val;
                    l2=l2.next;
                }
                int num = total%10;
                c=total/10;
                dummy.next = new ListNode(num);
                dummy = dummy.next;
             }
             return res.next;
    }
}