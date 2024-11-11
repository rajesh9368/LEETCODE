class Solution {
    public boolean primeSubOperation(int[] n) {
        for (int i = n.length - 1; i > 0; i--) {
            if (n[i] <= n[i - 1]) {
                int p = n[i - 1] - n[i] + 1;
                while (n[i - 1] - p > 0 && !isPrime(p)) p++;
                n[i - 1] -= p;
            }
        }

        for (int i = 1; i < n.length; i++) {
            if (n[i - 1] >= n[i] || n[i - 1] <= 0) return false;
        }

        return true;
    }

    public boolean isPrime(int a) {
        if (a <= 1) return false;
        for (int i = 2; i <= Math.sqrt(a); i++) {
            if (a % i == 0) return false;
        }
        return true;
    }
}