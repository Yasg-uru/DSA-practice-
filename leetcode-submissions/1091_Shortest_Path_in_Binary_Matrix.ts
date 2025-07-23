function shortestPathBinaryMatrix(grid: number[][]): number {
   const queue:[number , number][]= [[0 , 0 ]];
   const directions: [number, number][] = [
    [-1, -1], [1, 0], [-1, 0], [-1, 1], [0, 1], 
    [1, 1], [1, 0], [1, -1], [0, -1]
];

    const m : number = grid.length;
    const n : number = grid[0].length;
    let levels : number = 0 ;

    if(grid[0][0]==1 || m==0 || n==0){
        return -1 ;

    }
    grid[0][0]=1 ;
    
    while(queue.length>0){
        let size:number = queue.length;
        while(size--){
            const [i  , j]= queue.shift()!;
            if(i==m-1 && j==n-1){
                return levels+1;
            }
            for(const dir of directions ){
                const i_:number = dir[0]+i;
                const j_ : number = dir[1]+j;
                if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]==0){
                    queue.push([i_, j_]);
                    grid[i_][j_]= 1;
                    
                }
            }
        }
        levels++;
    }
    return -1 ;
};
