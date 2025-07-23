function minChanges(s: string): number {
    let changes:number =0;
    for(let i=0;i<s.length-1;i++){
        if(s[i]!==s[i+1]){
            changes+=1;
        }
    }
    return changes ;
};