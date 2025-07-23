function firstCompleteIndex(arr: number[], mat: number[][]): number {
    const map:Map<number,[number,number]>=new Map();
    for(let i:number=0;i<mat.length;i++){
        for(let j:number =0;j<mat[0].length;j++){
            map.set(mat[i][j],[i,j]);
        }
    }
    for(let i:number =0;i<arr.length;i++){
        const [row,col]=map.get(arr[i]);
        mat[row][col]*=-1;
        if(checkRowPainted(row,mat) || checkColPainted(col,mat)){
            return i;
        }
    }
    return -1;
};
function checkRowPainted(row:number,mat:number[][]):boolean{
    for(let col:number=0;col<mat[0].length;col++){
        if(mat[row][col]>0){
            return false;
        }
    }
    return true ;
}
function checkColPainted(col:number ,mat:number[][]):boolean{
    for(let row:number =0;row<mat.length;row++){
         if(mat[row][col]>0){
            return false;
        }
    }
    return true ;
}