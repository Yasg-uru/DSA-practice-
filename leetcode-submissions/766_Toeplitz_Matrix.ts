function isToeplitzMatrix(matrix: number[][]): boolean {
    const m : number = matrix.length, n = matrix[0].length;
 
    for(let i:number =0 ;i<m;i++){
         if(startDiagonal(matrix[i][0], i, 0  , m , n, matrix)==false){

                return false;}
        
    }
        for(let j:number =0 ;j<n;j++){
           
                if(startDiagonal(matrix[0][j], 0 , j , m , n, matrix)==false){

                return false;}
           
        }
    
    return true ;
};
function startDiagonal(pickedEle :number , i :number , j:number , m :number , n : number , matrix:number[][]):boolean{
    let row :number = i , col :number = j;
    while(row<m && col<n ){
        if(pickedEle!==matrix[row][col]){
            return false;
        }else{
            row++;
            col++;
        }
    }
    return true ;
    
}