function minBitFlips(start: number, goal: number): number {
    let xor_value= start ^ goal;
    let ans:number=0;
    while(xor_value>0){
        ans+=xor_value & 1;
        xor_value>>=1;
    }
    return ans;

};