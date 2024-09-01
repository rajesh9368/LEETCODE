class Solution {
    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        String color = "";
        char col = coordinate1.charAt(0);
        char row = coordinate1.charAt(1);
        if ((col == 'a' || col == 'c' || col == 'e' || col == 'g') && 
            (row == '1' || row == '3' || row == '5' || row == '7')) {
            color = "black";
        } else if ((col == 'b' || col == 'd' || col == 'f' || col == 'h') && 
                   (row == '2' || row == '4' || row == '6' || row == '8')) {
            color = "black";
        } else {
            color = "white";
        }
        String color2 = "";
        char col2 = coordinate2.charAt(0);
        char row2 = coordinate2.charAt(1);
        if ((col2 == 'a' || col2 == 'c' || col2 == 'e' || col2 == 'g') && 
            (row2 == '1' || row2 == '3' || row2 == '5' || row2 == '7')) {
            color2 = "black";
        } else if ((col2 == 'b' || col2 == 'd' || col2 == 'f' || col2 == 'h') && 
                   (row2 == '2' || row2 == '4' || row2 == '6' || row2 == '8')) {
            color2 = "black";
        } else {
            color2 = "white";
        }
        return color.equals(color2);
    }
}
