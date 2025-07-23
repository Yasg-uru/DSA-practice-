let isIsland: boolean;

function dfs(i: number, j: number, n: number, m: number, grid1: number[][], grid2: number[][]): void {
    if (grid1[i][j] !== grid2[i][j]) {
        isIsland = false;
    }
    grid1[i][j] = grid2[i][j] = 0; // mark as visited
    const directions: number[][] = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    for (let k = 0; k < 4; k++) {
        let x: number = i + directions[k][0];
        let y: number = j + directions[k][1];
        if (x >= 0 && y >= 0 && x < n && y < m && grid2[x][y] === 1) {
            dfs(x, y, n, m, grid1, grid2);
        }
    }
}

function countSubIslands(grid1: number[][], grid2: number[][]): number {
    let count: number = 0;
    let n = grid1.length;
    let m = grid1[0].length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid2[i][j] === 1) {
                isIsland = true; // Reset global variable for each island check
                dfs(i, j, n, m, grid1, grid2);
                if (isIsland) {
                    count++;
                }
            }
        }
    }
    return count;
}
