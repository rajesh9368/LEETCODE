class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            int j = i + 1;
            while(j < n && arr[j] <= arr[i]) {
                j++;
            }
            if(j != n) {
                ans[i] = j - i;
            }
        }
        
        return ans;
    }
};