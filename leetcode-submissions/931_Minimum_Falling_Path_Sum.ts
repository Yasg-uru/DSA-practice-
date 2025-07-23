function minFallingPathSum(matrix: number[][]): number {
    const m = matrix.length, n = matrix[0].length;
    const dp: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
    let minAns = Number.MAX_SAFE_INTEGER;

    for (let j = 0; j < n; j++) {
        minAns = Math.min(solve(0, j, m, n, matrix, dp), minAns);
    }

    return minAns;
}

function solve(i: number, j: number, m: number, n: number, matrix: number[][], dp: number[][]): number {
    if (i < 0 || j < 0 || i >= m || j >= n) {
        return Number.MAX_SAFE_INTEGER;
    }

    if (i === m - 1) {
        return matrix[i][j];
    }

    if (dp[i][j] !== -1) {
        return dp[i][j];
    }

    const current = matrix[i][j];
    return dp[i][j] = current + Math.min(
        solve(i + 1, j - 1, m, n, matrix, dp),
        solve(i + 1, j,     m, n, matrix, dp),
        solve(i + 1, j + 1, m, n, matrix, dp)
    );
}
