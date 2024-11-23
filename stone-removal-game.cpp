class Solution {
    public boolean canAliceWin(int n) {
        if(n<10) return false;
        if(n==10) return true;
        int current = 10;
        boolean alice = true;
        while(n>=current){
            n-=current;
            current--;
            alice=!alice;
        }
        return !alice;
    }
}