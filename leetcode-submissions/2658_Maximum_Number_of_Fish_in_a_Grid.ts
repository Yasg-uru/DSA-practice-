function findMaxFish(grid: number[][]): number {
    let maxFishes:number =0;

    for(let i:number =0;i<grid.length;i++){
        for(let j:number =0;j<grid[0].length;j++){
maxFishes=Math.max(maxFishes,BFS(i,j,grid));
        }
    }
    return maxFishes;
};
function BFS (i:number ,j:number ,grid:number[][]):number {
    const m:number =grid.length;
    const n:number =grid[0].length;
    const directions :[number,number][]=[[0,1],[0,-1],[1,0],[-1,0]];
    const queue:[number,number][]=[[i,j]];
    let Fishes:number =0;
    
    while(queue.length>0){
    const [i,j]=queue.shift();
    if(grid[i][j]===0){
        continue;
    }
    Fishes+=grid[i][j];

    grid[i][j]=0;
    for(const [row,col] of directions){
        const i_:number =row+i;
        const j_:number=col+j;
    if(i_>=0 && j_>=0 && i_<m && j_<n && grid[i_][j_]>0){
        queue.push([i_,j_]);
    }
        
    }



}
return Fishes;



}