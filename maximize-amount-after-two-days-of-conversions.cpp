class Solution {
public Map<String, Map<String, Double>> op(List<List<String>> pairs, double[] rates) {
        Map<String, Map<String, Double>> g = new HashMap<>();
        for (int i = 0; i < pairs.size(); i++) {
            String f = pairs.get(i).get(0);
            String t = pairs.get(i).get(1);
            double ra= rates[i];
            g.putIfAbsent(f, new HashMap<>());
            g.putIfAbsent(t, new HashMap<>());
            g.get(f).put(t, ra);
            g.get(t).put(f, 1.0 / ra);
        }
        return g;
    }
    public Map<String, Map<String, Double>> fw(Map<String, Map<String, Double>> graph) {
        Map<String, Map<String, Double>> dis = new HashMap<>();
        for (String start : graph.keySet()) {
            dis.putIfAbsent(start, new HashMap<>());
            for (String end : graph.keySet()) {
                if (start.equals(end)) {
                    dis.get(start).put(end, 1.0);
                } else if (graph.get(start).containsKey(end)) {
                    dis.get(start).put(end, graph.get(start).get(end));
                } else {
                    dis.get(start).put(end, 0.0);
                }
            }
        }
        for (String m : graph.keySet()) {
            for (String s : graph.keySet()) {
                for (String e : graph.keySet()) {
                    double cur = dis.get(s).get(e);
                    double np = dis.get(s).get(m) * dis.get(m).get(e);
                    dis.get(s).put(e, Math.max(cur, np));
                }
            }
        }
        return dis;
    }
public double maxAmount(String initialCurrency, List<List<String>> pairs1, double[] rates1, List<List<String>> pairs2, double[] rates2) {
        Map<String, Map<String, Double>> g1 = op(pairs1, rates1);
        Map<String, Map<String, Double>> g2 = op(pairs2, rates2);
        Map<String, Map<String, Double>> sp1 = fw(g1);
        Map<String, Map<String, Double>> sp2 = fw(g2);
        Map<String, Double> ir = new HashMap<>();
        for (String currency : sp1.get(initialCurrency).keySet())ir.put(currency, sp1.get(initialCurrency).get(currency));
        ir.put(initialCurrency, 1.0);
        double maxi = 1.0;
        for (Map.Entry<String, Double> entry : ir.entrySet()) {
            String curr = entry.getKey();
            double r = entry.getValue();
            if (sp2.containsKey(curr))maxi = Math.max(maxi, r * sp2.get(curr).getOrDefault(initialCurrency, 0.0));
        }
        return maxi;
    }
}
