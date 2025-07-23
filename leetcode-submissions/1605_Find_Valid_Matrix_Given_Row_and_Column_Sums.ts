function restoreMatrix(rowSum: number[], colSum: number[]): number[][] {
    // we need to create two pointer and initializing the matrix 
    const n:number=rowSum.length;
    const m:number=colSum.length;

    const result:number[][]=Array.from({length:n},function(){ return Array(m).fill(0)});
    let i:number=0,j:number=0;
    while(i<n && j<m){
        let minele:number=Math.min(rowSum[i],colSum[j]);
        rowSum[i]-=minele;
        colSum[j]-=minele;
        result[i][j]=minele;
        if(rowSum[i]===0){
            i++;
        }else {
            j++;
        }
    }
return result;
};