class Solution {
    public boolean isAnagram(String s, String t) {
        //tc:o(nlogn+mlogm)
        //sc:o(1)
        char[] sa = s.toCharArray();
        char[] ta = t.toCharArray();
        Arrays.sort(sa);
        Arrays.sort(ta);
        return Arrays.equals(sa,ta);
    }
}