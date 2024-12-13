class Solution {
    public long findScore(int[] nums) {
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(
            (pair1, pair2) -> {
                if(!pair1.getKey().equals(pair2.getKey())) {
                    return pair1.getKey() - pair2.getKey();
                } else {
                    return pair1.getValue() - pair2.getValue();
                }
            }
        );

        for(int i = 0; i < nums.length; i ++) {
            pq.add(new Pair<>(nums[i], i));
        }
        
        long ans = 0;

        while(pq.size() > 0) {
            Pair<Integer, Integer> pair = pq.poll();
            int val = pair.getKey();
            int index = pair.getValue();

            //since nums range is +ve int, mark visited nums as -1 to skip processing them
            if(nums[index] == -1) {
                continue;
            }

            ans += val;
            int prev = index - 1;
            int next = index + 1;
            if(prev >= 0) {
                nums[prev] = -1;
            }
            if(next < nums.length) {
                nums[next] = -1;
            }
        }

        return ans;
    }
}