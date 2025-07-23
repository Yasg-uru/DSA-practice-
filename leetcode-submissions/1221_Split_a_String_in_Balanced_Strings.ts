function balancedStringSplit(s: string): number {
    let count :number =0;
    let maxStrings:number =0;
    for(let i:number =0;i<s.length;i++){
        if(s[i]==='R'){
            count++;
        }
        else {
            count--;
        }
        if(count===0){
            maxStrings++;
        }
    }
    return maxStrings;
};