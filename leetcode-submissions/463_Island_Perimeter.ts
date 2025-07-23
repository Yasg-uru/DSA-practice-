function islandPerimeter(grid: number[][]): number {
    // to solve this problem we dont need to make dfs/bfs traversal
    const m:number = grid.length;
    const n:number=grid[0].length; 
    let count:number =0;
    for(let i:number =0;i<m;i++){
        for(let j:number=0;j<n;j++){
            if(grid[i][j]===1){
                // we need to check wether in up down right left boundary 
                if(j===0 || (j>0 && grid[i][j-1]===0)){
                    count++;
                }// left
                if(j===n-1 || (j<n-1 && grid[i][j+1]===0)){
                    count++;
                }//right
                if(i===0 || (i>0 && grid[i-1][j]===0)){
                    count++;
                }
                if(i===m-1 || (i<m-1 && grid[i+1][j]===0)){
                    count++;
                }
            }
        }
    }
    return count ;
};