function largestIsland(grid: number[][]): number {
    let maxArea: number =0;
    let n :number = grid.length;
   const visited: boolean[][] = Array.from({ length: n }, () => 
    Array.from({ length: n }, () => false)
);

    const directions :[number,number][]=[[-1,0],[1,0],[0,1],[0,-1]];
    const map :Map<number, number>=new Map();

    let id:number =2;
    for(let i:number =0;i<n ;i++){
        for(let j:number =0;j<n ;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                const size :number = DFS(i,j,grid,visited,id,n,directions);
                maxArea=Math.max(maxArea, size);
                map.set(id, size);
                id++;


            }
        }
    }
    for(let i:number =0;i<n;i++){
        for(let j:number =0;j<n;j++){
            if(grid[i][j]===0){
                const uniqueVals:Set<number>=new Set();
                for(const [row,col] of directions){
                    const i_:number =row+i;
                    const j_:number = col+j;
                    if(i_>=0 && j_>=0 && i_<n && j_<n && grid[i_][j_]!==0){
                        uniqueVals.add(grid[i_][j_]);

                    }
                }
                let overallArea:number =1;
                for(const val of uniqueVals)
                {
                    const size :number = map.get(val)!;
                    overallArea+=size;
                }
                maxArea= Math.max(maxArea, overallArea);
            }
        }
    }
    return maxArea===0?(n*n):maxArea;
};
function DFS (i :number , j:number , grid:number[][],visited:boolean[][], id :number,n:number, directions :[number,number][]){
    //base case 
    if(i< 0 || j < 0 || j>=n || i>=n || grid[i][j]===0 || visited[i][j]) return 0;
    let size:number =1;
    grid[i][j]=id;
    visited[i][j]=true;
    for(const [row , col ] of directions){
        const i_:number = row+i;
        const j_:number = col+j;
        size+=DFS(i_, j_, grid, visited, id ,n, directions);

    }
    return size ;
}