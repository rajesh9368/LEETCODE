class Solution {
    public int findCircleNum(int[][] isConnected) {
        int v = isConnected.length;
        boolean[] vis = new boolean[v];
        int cnt = 0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
            bfs(i, vis, isConnected);
            cnt++;
            }
        }
        return cnt;
    }
    public void bfs(int v, boolean[] vis, int[][] isConnected){
Queue<Integer> que = new LinkedList<>();
que.add(v);
vis[v] = true;
while(!que.isEmpty()){
    int node = que.remove();
    for(int j=0;j<isConnected.length;j++){
        if(isConnected[node][j]==1 && !vis[j]){
            que.add(j);
            vis[j] = true;

        }
    }
}
    }
}