class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int r = matrix.length;
        int c = matrix[0].length;
        int tr = 0, br = r - 1; 
        int lc = 0, rc = c - 1; 
        int totalelements = 0;
        int total = r * c;
        while (totalelements < total) {
            for (int i = lc; i <= rc && totalelements < total; i++) {
                ans.add(matrix[tr][i]);
                totalelements++;
            }
            tr++; 
            for (int i = tr; i <= br && totalelements < total; i++) {
                ans.add(matrix[i][rc]);
                totalelements++;
            }
            rc--;
            for (int i = rc; i >= lc && totalelements < total; i--) {
                ans.add(matrix[br][i]);
                totalelements++;
            }
            br--; 
            for (int i = br; i >= tr && totalelements < total; i--) {
                ans.add(matrix[i][lc]);
                totalelements++;
            }
            lc++;
        }
        return ans;
    }
}
