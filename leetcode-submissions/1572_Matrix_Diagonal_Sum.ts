function diagonalSum(grid: number[][]): number {
     const n : number = grid.length;
    let colNumber:number=0 , sum :number =0 ;
    
    for(let i:number =0 ;i<n ;i++){
       sum+=grid[i][i];
        
    }
    
    for(let i = n-1;(i>=0 && colNumber<n);i--){
       sum+=grid[i][colNumber];
       
        colNumber++;
    }
   if(n%2!==0){
     const mid= Math.floor(n/2);
    sum-=grid[mid][mid];
   }
   
    return sum ;
};