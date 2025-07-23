function xorQueries(arr: number[], queries: number[][]): number[] {
    const ans:number[]=[];
    for(const query of queries){
        let result:number=0;
        for(let i=query[0];i<=query[1];i++){
            result^=arr[i];
        }
        ans.push(result);
    }
    return ans;
};