class Solution {
    int[] countDistance(int start, int[] edges)
    {
      int n = edges.length;
      int dist[] = new int[n];
      Arrays.fill(dist, Integer.MAX_VALUE);
      dist[start] = 0; 
      boolean vis[] = new boolean[n];

      Queue<Integer> q = new LinkedList<>();
      q.offer(start);
      while(!q.isEmpty())
      {
       int node = q.poll();
       if(vis[node])
       continue; 
       vis[node] = true;
       int nextNode = edges[node];
       if(nextNode!=-1 && !vis[nextNode])
       {
       dist[nextNode] = 1 + dist[node];
       q.offer(nextNode);
       }
      }
      return dist;
    }
    public int closestMeetingNode(int[] edges, int node1, int node2) {
    int dist1[] = countDistance(node1, edges);
    int dist2[] = countDistance(node2, edges);
    int n = edges.length;
    int minDistance = Integer.MAX_VALUE;
    int ansNode = -1;

    for(int i=0; i<n; i++)
    {
      int maxVal = Math.max(dist1[i], dist2[i]);
      if(minDistance>maxVal)
      {
        minDistance = maxVal;
        ansNode = i;
      }
     
    }
    
      return ansNode;
    }
}