function partitionLabels(s: string): number[] {
    let mp:Map<string, number> = new Map();
    let lastUsedIndex :number=0 , maxIndex :number =-1;
    const n :number = s.length, ans :number[] =[];
    for(let i:number =0;i<n;i++){
        mp.set(s[i], i);
    }
    for(let i:number =0;i<n;i++){
        maxIndex = Math.max(maxIndex , mp.get(s[i]));
        if(maxIndex==i){
            ans.push(i-lastUsedIndex+((ans.length===0)?1:0));
            lastUsedIndex = i ;
            maxIndex = -1;
        }
    }
    return ans ;
};