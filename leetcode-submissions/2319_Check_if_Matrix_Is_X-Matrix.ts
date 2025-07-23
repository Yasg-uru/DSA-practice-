function checkXMatrix(grid: number[][]): boolean {
    const n : number = grid.length;
    let colNumber:number=0 ;
    const visited:boolean[][]= Array.from({length:n}, ()=>Array.from({length:n},()=>false));
    for(let i:number =0 ;i<n ;i++){
        if(grid[i][i]===0){

            return false;
        }
        visited[i][i]= true;
    }
    
    for(let i = n-1;(i>=0 && colNumber<n);i--){
        if(grid[i][colNumber]===0){
            return false;
        }
        visited[i][colNumber]= true ;
        colNumber++;
    }
    for(let i:number =0 ;i<n;i++){
        for(let j:number =0 ;j<n;j++){
            if(!visited[i][j] && grid[i][j]>0){
                return false;
            }
        }
    }
    return true ;
};