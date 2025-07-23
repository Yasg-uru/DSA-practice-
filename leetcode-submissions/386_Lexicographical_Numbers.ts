function lexicalOrder(n: number): number[] {
    const ans:number[]=[];
    for(let i=1;i<=n;i++){
        ans.push(i);

    }
    ans.sort((a,b)=>(a.toString()).localeCompare(b.toString()));
    return ans;
};