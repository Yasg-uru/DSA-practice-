/**
 Do not return anything, modify matrix in-place instead.
 */
 
 function setcol(matrix:number[][],col:number){
for(let i:number=0;i<matrix.length;i++){
    if(matrix[i][col]!=0){
        matrix[i][col]=-10;
    }
}
 }
function setrow(matrix:number[][],row:number){
    for(let i:number=0;i<matrix[0].length;i++){
    if(matrix[row][i]!=0){
        matrix[row][i]=-10;
    }
}
 }
function setZeroes(matrix: number[][]): void {
    for(let i:number=0;i<matrix.length;i++){
        for(let j:number=0;j<matrix[0].length;j++){
            if(matrix[i][j]===0){
                setrow(matrix,i);
                setcol(matrix,j);
            }
        }
    }
    for(let i:number=0;i<matrix.length;i++){
        for(let j:number=0;j<matrix[0].length;j++){
            if(matrix[i][j]===-10){
                matrix[i][j]=0;
            }
        }
    }
};