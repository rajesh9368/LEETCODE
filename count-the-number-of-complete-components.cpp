class Solution {
    class Edge {
        int src;
        int dest;

        public Edge(int src, int dest) {
            this.src = src;
            this.dest = dest;
        }
    }

    public void createGraph(int edges[][], ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.length; i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            graph[src].add(new Edge(src, dest));
            graph[dest].add(new Edge(dest, src));
        }
    }

    public int countCompleteComponents(int n, int[][] edges) {
        ArrayList<Edge> graph[] = new ArrayList[n];
        createGraph(edges, graph);

        int ans = 0;
        boolean vis[] = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {

                Queue<Integer> q = new LinkedList<>();
                List<Integer> connect = new ArrayList<>();

                q.add(i);
                vis[i] = true;
                
                while (!q.isEmpty()) {
                    int curr = q.poll();
                    connect.add(curr);
                    for (Edge e : graph[curr]) {
                        if (!vis[e.dest]) {
                            q.add(e.dest);
                            vis[e.dest] = true;
                        }
                    }
                }

                boolean check = true;
                for (int node : connect) {
                    if (graph[node].size() != connect.size() - 1) {
                        check = false;
                        break;
                    }
                }

                if (check == true) {
                    ans++;
                }
            }
        }
        return ans;
    }
}