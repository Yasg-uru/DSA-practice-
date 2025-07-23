function findThePrefixCommonArray(A: number[], B: number[]): number[] {
    const map:Map<number,number>=new Map();
    let count:number =0;
    const result:number[]=new Array(A.length).fill(0);
    for(let i:number =0;i<A.length;i++){
        if(map.has(A[i])){
            map.set(A[i],map.get(A[i])+1);
        }else {
            map.set(A[i],1);
        }
        if(map.get(A[i])===2){
            count++;
        }
        if(map.has(B[i])){
            map.set(B[i],map.get(B[i])+1);
        }else {
            map.set(B[i],1);
        }
        if(map.get(B[i])===2){
            count++;
        }
    result[i]=count;
    }
    return result ;
};