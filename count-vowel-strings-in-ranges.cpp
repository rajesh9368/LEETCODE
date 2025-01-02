// class Solution {
//     public int[] vowelStrings(String[] words, int[][] queries) {
//         int n = words.length;
//         int m = queries.length;
//         int[] ans = new int[m];
//         for(int j=0;j<m;j++){
//             int cnt=0;
//             int l=queries[j][0];
//             int r=queries[j][1];
//             for(int i=l;i<=r;i++){
//                 String s = words[i];
//                 if((s.charAt(0)=='a'||s.charAt(0)=='e'||s.charAt(0)=='i'||s.charAt(0)=='o'||s.charAt(0)=='u') && 
//                 (s.charAt(s.length()-1)=='a' || s.charAt(s.length()-1)=='e' ||s.charAt(s.length()-1)=='i'||s.charAt(s.length()-1)=='o'||
//                 s.charAt(s.length()-1)=='u')) cnt++;
//             }
//             ans[j]=cnt;
//         }
//         return ans;
//     }
// } TLE
class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length;
        int[] prefixSum = new int[n + 1]; 
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));   
        for (int i = 0; i < n; i++) {
            String word = words[i].toLowerCase(); 
            if (vowels.contains(word.charAt(0)) && vowels.contains(word.charAt(word.length() - 1))) prefixSum[i + 1] = prefixSum[i] + 1;
            else prefixSum[i + 1] = prefixSum[i];
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            result[i] = prefixSum[end + 1] - prefixSum[start];
        }

        return result;
    }
}