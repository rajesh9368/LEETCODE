class Solution {
    public boolean check(int row, int col, char[][] box) {
        int duprow = row, dupcol = col;
        for (int i = 0; i < box.length; i++) {
            if (box[i][col] == 'Q') return false;
        }
        for (int j = 0; j < box.length; j++) {
            if (box[row][j] == 'Q') return false;
        }
        row = duprow; col = dupcol;
        while (row >= 0 && col >= 0) {
            if (box[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = duprow; col = dupcol;
        while (row < box.length && col >= 0) {
            if (box[row][col] == 'Q') return false;
            row++; col--;
        }
        row = duprow; col = dupcol;
        while (row >= 0 && col < box.length) {
            if (box[row][col] == 'Q') return false;
            row--; col++;
        }
        row = duprow; col = dupcol;
        while (row < box.length && col < box.length) {
            if (box[row][col] == 'Q') return false;
            row++; col++;
        }
        return true;
    }

    public void operation(int col, int n, char[][] box, List<String> temp, List<List<String>> ans) {
        if (col == n) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        for (int row = 0; row < n; row++) {
            if (check(row, col, box)) {
                char[] rowArray = new char[n];
                Arrays.fill(rowArray, '.');
                rowArray[row] = 'Q';
                temp.add(new String(rowArray));
                box[row][col] = 'Q';
                operation(col + 1, n, box, temp, ans);
                box[row][col] = '.';
                temp.remove(temp.size() - 1);
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        char[][] box = new char[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(box[i], '.');
        }
        List<String> temp = new ArrayList<>();
        List<List<String>> ans = new ArrayList<>();
        operation(0, n, box, temp, ans);
        return ans;
    }
}
