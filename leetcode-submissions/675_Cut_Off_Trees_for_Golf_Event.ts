function cutOffTree(forest: number[][]): number {
    if(forest[0][0]===0) return -1; 
    const m = forest.length, n = forest[0].length;
    let distance  = -1;
    const directions:[number , number][] = [[0 , 1] , [1, 0 ], [0 , -1], [ -1 , 0 ]];
    const queue:[number , number   , number][]  =[[0 , 0, 0 ]];
    const trees :[number , number , number][]  = [];
    for(let i:number =0 ;i<m;i++){
        for(let j:number =0;j<n;j++){
            if(forest[i][j]>1){
                trees.push([forest[i][j], i , j]);
            }
            
        }
    }
    trees.sort((a, b)=>a[0]-b[0]);
    function bfs(sx: number, sy: number, tx: number, ty: number): number {
        if (sx === tx && sy === ty) return 0;
        const visited = Array.from({ length: m }, () => Array(n).fill(false));
        const queue: [number, number, number][] = [[sx, sy, 0]];
        visited[sx][sy] = true;
        const dirs = [[0,1], [1,0], [0,-1], [-1,0]];

        while (queue.length) {
            const [x, y, d] = queue.shift()!;
            for (const [dx, dy] of dirs) {
                const nx = x + dx, ny = y + dy;
                if (
                    nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    !visited[nx][ny] && forest[nx][ny] !== 0
                ) {
                    if (nx === tx && ny === ty) return d + 1;
                    visited[nx][ny] = true;
                    queue.push([nx, ny, d + 1]);
                }
            }
        }
        return -1; // target unreachable
    }
        let totalDistance =0, currx=0 , curry=0  ;
    for(const [_ , i , j] of trees){
        let d = bfs(currx, curry , i , j);
        if(d===-1) return -1;
        
        totalDistance +=d;
        currx = i ;
        curry = j ;
    }
    return totalDistance ;
        
        
    
};
