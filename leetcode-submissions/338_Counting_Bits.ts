function countBits(n: number): number[] {
    // this question is from the mathematical observation 
    // event number has same bit as their half number contains 
    // and odd number has same bit +1 as their half number contains 
    const result:number[]= new Array(n+1).fill(0);
    for(let i:number = 1;i<=n;i++){
        if(i%2===1){
            result[i]= result[Math.floor(i/2)]+1;
        }else{
            result[i]= result[Math.floor(i/2)];
        }
    }
    return result ;
};