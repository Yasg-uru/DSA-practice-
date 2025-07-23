function findContentChildren(g: number[], s: number[]): number {
    let ans :number =0;
    g.sort((a,b)=>a-b);
    s.sort((a,b)=>a-b);
    let i:number =0;
    let j:number =0;
    while(i<g.length && j<s.length){
        if(s[j]>=g[i]){
            ans ++;
            i++;
            j++;
        }else if(s[j]<g[i]){
            j++;
        }
    }
    return ans ;
    
    
};