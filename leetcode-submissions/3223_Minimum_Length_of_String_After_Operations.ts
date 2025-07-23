function minimumLength(s: string): number {
    const freq:number[]=new Array(26).fill(0);
    for(const c of s){
        if(c>='a' && c<='z'){
            let index:number =c.charCodeAt(0)-'a'.charCodeAt(0);
            freq[index]+=1;
            if(freq[index]>2){
                freq[index]-=2;
            }
        }
    }
    let ans :number =0;
    for(const f of freq){
if(f===0) continue;
ans+=f;
    }
    return ans ;
};