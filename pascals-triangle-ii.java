class Solution {
    public long operation(int row, int col) {
        long ans = 1;
        for (int i = 0; i < col; i++){
            ans = ans*(row - i);
            ans = ans/(i + 1);
        }
        return ans;
    }
    public List<Integer> getRow(int rowIndex) {
        ArrayList<Integer> temp = new ArrayList<>();
        for (int j = 0; j <= rowIndex; j++) {
            temp.add((int)operation(rowIndex, j));
        }
        return temp;
    }
}