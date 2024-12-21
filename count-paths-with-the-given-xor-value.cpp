class Solution {
    public int countPathsWithXorValue(int[][] grid, int k) {
        int r = grid.length,c = grid[0].length;
        Map<Integer, Integer>[][] mp = new HashMap[r][c];
        for (int i=0; i<r;i++) {
            for (int j=0;j<c;j++) {mp[i][j] = new HashMap<>();
            } }
        int m = 1_000_000_007;
        mp[0][0].put(grid[0][0], 1);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (Map.Entry<Integer, Integer> entry : mp[i][j].entrySet()) {
                    int curr = entry.getKey(),cnt = entry.getValue();
                    if (j + 1 < c) {
                        int ne = curr ^ grid[i][j + 1];mp[i][j + 1].put(ne, (mp[i][j + 1].getOrDefault(ne, 0) + cnt) % m);
                    }
                    if (i + 1 < r) {
                        int ne = curr ^ grid[i + 1][j];mp[i + 1][j].put(ne, (mp[i + 1][j].getOrDefault(ne, 0) + cnt) % m);
                    }
                }
            }
        }return mp[r-1][c-1].getOrDefault(k, 0);
    }
}