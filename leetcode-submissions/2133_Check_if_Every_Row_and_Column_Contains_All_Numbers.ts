function checkValid(matrix: number[][]): boolean {
    const n : number = matrix.length;
    
    for(let i:number =0 ;i<n;i++){
        const rowSeen:boolean[]= new Array(n+1).fill(false);

        for(let j:number =0;j<n;j++){
           const num :number = matrix[i][j];
           if(num<1 || num>n || rowSeen[num]){
            return false;
           }
           rowSeen[num]= true ;
        }
    }

    for(let  j :number =0 ;j<n;j++){
        const colSeen:boolean[]= new Array(n+1).fill(false);

        for(let i:number =0;i<n;i++){
           const num :number = matrix[j][i];
           if(num<1 || num>n || colSeen[num]){
            return false;
           }
           colSeen[num]= true ;
        }
    }
    return true ;
};