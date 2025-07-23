function smallestEquivalentString(s1: string, s2: string, baseStr: string): string {
    const adj:Map<string , string[]>= new Map();
    const n:number = s1.length;
    for(let i:number =0 ;i<n;i++){
        if(!adj.has(s1[i])){
            adj.set(s1[i], []);

        }
        if(!adj.has(s2[i])){
            adj.set(s2[i] ,[]);
        }
       adj.get(s1[i])!.push(s2[i]);
        adj.get(s2[i])!.push(s1[i]);

    }
    let ans:string = "";
    for(let i:number =0;i<baseStr.length;i++ ){
        const visited:boolean[]= new Array(26).fill(false);
        const ch :string = baseStr[i];
         if (!adj.has(ch)) {
            ans += ch;
        } else {
            ans += dfs(adj, visited, ch);
        }
    }
    return ans ;
};
function dfs(adj:Map<string , string[]>, visited:boolean[], curr:string):string {
    const index = curr.charCodeAt(0)-"a".charCodeAt(0);
    visited[index]= true ;
    let minCharacter :string = curr; 
    //ab isko mark karne ke baad neighbors explore karlo 
    for(const nbr of adj.get(curr)!){
        const Nbrindex = nbr.charCodeAt(0)-"a".charCodeAt(0);
        if(visited[Nbrindex]==false){
             const ans :string = dfs(adj , visited , nbr);
            if(minCharacter>ans){
                minCharacter = ans ;
            }
            
        }
    }
    return minCharacter;
}