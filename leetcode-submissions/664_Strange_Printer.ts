function strangePrinter(s: string): number {
    const n = s.length;
    const dp: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

    // Iterate over the string in reverse order
    for (let i = n - 1; i >= 0; i--) {
        dp[i][i] = 1; // Base case: single character requires one print
        for (let j = i + 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1] + 1; // Assume s[j] is printed in a new turn
            for (let k = i; k < j; k++) {
                // If s[k] and s[j] are the same, consider merging the printing operations
                if (s[k] == s[j]) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
                }
            }
        }
    }

    return dp[0][n - 1]; // The minimum turns to print the entire string
}
