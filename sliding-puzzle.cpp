class Solution {
    private static final String TARGET =  "1+2+3+4+5+0";
    private static final int[][] directions = {{-1,0},{1,0},{0,1},{0,-1}};
    public boolean wonState(String boardState){
        return TARGET.equals(boardState);
    }
    private class Pair{
        String key;
        int[] pos;
        int moves;
        Pair(String k, int[] pos, int move){
            this.key = k;
            this.pos = pos;
            this.moves = move;
        }
    }
    public String boardtoState(int[][] board){
        StringBuilder res = new StringBuilder();
        for (int[] row:board){
            for (int num: row){
                res.append(num).append("+");
            }
        }
        String result = res.toString();
        return result.substring(0,result.length()-1);
    }
    public int[] getPos(int[][] board){
        for (int i=0; i<board.length ;i++){
            for (int j=0 ;j<board[0].length ;j++){
                if (board[i][j] == 0) return new int[]{i,j};
            }
        }
        throw new IllegalArgumentException("Wrong Input");
    }
    
    public int slidingPuzzle(int[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) return -1;

        // Get the initial position of 0
        int[] pos = getPos(board);
        String startState = boardtoState(board);
        if (wonState(startState)) return 0;// already won

        Queue<Pair> q = new LinkedList<>();// enque CurrState
        Set<String> vis = new HashSet<>();

        q.add(new Pair(startState,pos,0));
        vis.add(startState);

        while(!q.isEmpty()){
            Pair curr = q.poll();
            int[] currPos = curr.pos;
            String currState = curr.key;
            int currMove = curr.moves;
            
            int[][] currBoard = new int[2][3];
            String[] digits = currState.split("\\+");
            for (int i=0 ;i<6 ;i++){
                currBoard[i/3][i%3] = Integer.parseInt(digits[i]);
            }

            for (int[] dir : directions){
                int nextRow = currPos[0] + dir[0] ;
                int nextCol = currPos[1] + dir[1] ;
                // Check 
                
                if (nextRow >= 0 && nextCol >= 0 && nextRow <2 && nextCol <3 ){
                    int[][] nextBoard = new int[2][3];
                    for (int i = 0 ;i<2 ;i++){
                        for (int j = 0 ; j<3 ;j++){
                            nextBoard[i][j] = currBoard[i][j];
                        }
                    }
                    nextBoard[currPos[0]][currPos[1]] = nextBoard[nextRow][nextCol];
                    nextBoard[nextRow][nextCol] = 0;
                    // swap 0 and adjacent
                    String newState = boardtoState(nextBoard);
                    if (!vis.contains(newState)){
                        if (wonState(newState)) return currMove+1;
                        vis.add(newState);
                        q.add(new Pair(newState,new int[]{nextRow,nextCol}, currMove+1));
                    }

                }
            }
        }
        return -1;
    }
    
}