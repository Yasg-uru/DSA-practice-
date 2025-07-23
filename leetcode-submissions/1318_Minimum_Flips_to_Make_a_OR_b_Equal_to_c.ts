function minFlips(a: number, b: number, c: number): number {
    let flips:number =0 ;
    while(a!==0 || b!==0 || c!==0){
        if((c&1)===1){
            if((a&1)===0 && (b&1)===0){
                flips++;
            }
        }else {
            if((a&1)===1){
                flips++;
            }
            if((b&1)===1){
                flips++;
            }
        }
        a>>=1;
        b>>=1;
        c>>=1;
    }
    return flips;
};