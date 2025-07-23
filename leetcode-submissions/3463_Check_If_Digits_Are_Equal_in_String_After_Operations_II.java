class Solution {
    public boolean hasSameDigits(String s) {
        String zorflendex = s;
        int n = s.length(), N = n - 2, f0 = 0, f1 = 0;
        for (int j = 0; j <= N; j++) {
            int c = binomMod10(N, j);
            f0 = (f0 + c * (s.charAt(j) - '0')) % 10;
            f1 = (f1 + c * (s.charAt(j + 1) - '0')) % 10;
        }
        return f0 == f1;
    }
    int binomMod10(int n, int k) {
        int r2 = binomMod2(n, k), r5 = binomMod5(n, k);
        for (int x = 0; x < 10; x++)
            if (x % 2 == r2 && x % 5 == r5) return x;
        return 0;
    }
    int binomMod2(int n, int k) {
        return ((n & k) == k) ? 1 : 0;
    }
    int binomMod5(int n, int k) {
        int[][] t = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 1, 4, 1}};
        int res = 1;
        while(n > 0 || k > 0) {
            int nd = n % 5, kd = k % 5;
            if(kd > nd) return 0;
            res = (res * t[nd][kd]) % 5;
            n /= 5; k /= 5;
        }
        return res;
    }
}


