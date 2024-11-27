class Solution
{
    public int[] shortestDistanceAfterQueries(int n, int[][] queries)
    {
        int[] result = new int[queries.length];        
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++)
        {
            graph.put(i, new ArrayList<>());
            if (i < n - 1)
            {
                graph.get(i).add(i + 1); 
            }
        }        
        int shortestDistance = n - 1; 
        for (int q = 0; q < queries.length; q++)
        {
            int src = queries[q][0];
            int dest = queries[q][1];
            graph.get(src).add(dest);
            shortestDistance = calculateShortestPath(graph, n);
            result[q] = shortestDistance;
        }
        return result;
    }
    
    private int calculateShortestPath(HashMap<Integer, ArrayList<Integer>> graph, int n)
    {
        Queue<int[]> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        queue.add(new int[]{0, 0}); 
        visited[0] = true;
        while (!queue.isEmpty())
        {
            int[] current = queue.poll();
            int city = current[0];
            int distance = current[1]; 
            if (city == n - 1)
            {
                return distance;
            }
            for (int neighbor : graph.get(city))
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.add(new int[]{neighbor, distance + 1}); 
                }
            }
        }
        return Integer.MAX_VALUE; 
    }
}