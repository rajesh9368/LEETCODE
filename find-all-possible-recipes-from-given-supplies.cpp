class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Set<String> available = new HashSet<>(Arrays.asList(supplies));

        Map<String, List<String>> graph = new HashMap<>();
        for(int i=0;i<recipes.length;i++){
            graph.put(recipes[i], ingredients.get(i));
        }

        Set<String> visited = new HashSet<>();
        List<String> result = new ArrayList<>();

        for(String recipe : recipes){
            if(canMake(recipe, graph, available, visited, new HashSet<>())){
                result.add(recipe);
            }
        }
        return result;
    }

    private boolean canMake(String recipe, Map<String, List<String>> graph, Set<String> available, Set<String> visited, Set<String> tempVisited){

        if(available.contains(recipe)) return true;
        if(!graph.containsKey(recipe)) return false;
        if(tempVisited.contains(recipe)) return false;
        if(visited.contains(recipe)) return false;

        tempVisited.add(recipe);

        for(String ingredient : graph.get(recipe)){
            if(!canMake(ingredient, graph, available, visited, tempVisited)){
                visited.add(recipe);
                tempVisited.remove(recipe);
                return false;
            }
        }
        available.add(recipe);
        visited.add(recipe);
        tempVisited.remove(recipe);
        return true;
    }
}