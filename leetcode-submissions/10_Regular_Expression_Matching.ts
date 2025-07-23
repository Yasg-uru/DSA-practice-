function isMatch(s: string, p: string): boolean {
    const dp: number[][] = Array.from({ length: s.length + 1 }, () =>
        Array(p.length + 1).fill(-1)
    );
    return solve(0, 0, s, p, dp);
}

function solve(i: number, j: number, s: string, p: string, dp: number[][]): boolean {
    const n1 = s.length, n2 = p.length;

    if (j === n2) return i === n1;

    if (dp[i][j] !== -1) return dp[i][j] === 1;

    const currentMatch = i < n1 && (s[i] === p[j] || p[j] === ".");

    let result: boolean;

    if (j + 1 < n2 && p[j + 1] === "*") {
        result = solve(i, j + 2, s, p, dp) || (currentMatch && solve(i + 1, j, s, p, dp));
    } else {
        result = currentMatch && solve(i + 1, j + 1, s, p, dp);
    }

    dp[i][j] = result ? 1 : 0;
    return result;
}
