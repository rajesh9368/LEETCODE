class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
	int max = 0;
	for(int num: quantities) max = Math.max(max, num);
	int l=1, r=max, res = -1;
	while(l <= r) {
		int mid = l + (r-l)/2;
		int ct = 0;
		for(int i=0; i<quantities.length; i++) {
			ct += (quantities[i]/mid);
			ct += (quantities[i]%mid)>0? 1: 0;
		}
		if(ct <= n) {
			res = mid;
			r = mid-1;
		} else l = mid+1;
	}
	return res;
}
}