class Solution {
    public boolean canBeValid(String s, String locked) {
        if (s.length() % 2 == 1) return false;

        int openBrackets = 0;
        for (int i=0; i<s.length(); i++){
            if (locked.charAt(i) == '0' || s.charAt(i) == '(') openBrackets++;
            else{
                if (openBrackets == 0) return false;
                openBrackets--;
            }
        }

        int closedBrackets = 0;
        for (int j=s.length()-1; j>=0; j--){
            if (locked.charAt(j) == '0' || s.charAt(j) == ')') closedBrackets++;
            else{
                if (closedBrackets == 0) return false;
                closedBrackets--;
            }
        }

        return true;
    }
}