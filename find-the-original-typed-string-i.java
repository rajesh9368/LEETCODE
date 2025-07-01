class Solution {
    public int possibleStringCount(String word) {
        int count=0,sum=0;
        int fre[]=new int[26];
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            char ch=word.charAt(i);
            int j=i;
            count=0;
            while(j<n&&word.charAt(j)==ch)
            {
               count++;
               j++;
            }
            i=j-1;
            sum+=count-1;
        }
        return sum+1;
    }
}