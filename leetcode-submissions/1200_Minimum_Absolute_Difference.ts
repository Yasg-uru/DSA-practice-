function minimumAbsDifference(arr: number[]): number[][] {
    let minAbsDiff : number = Number.MAX_SAFE_INTEGER;
    const n : number = arr.length;
    arr.sort((a, b)=>a-b);
    console.log(arr);
    for(let i : number =0 ;i<n-1;i++){
        minAbsDiff= Math.min(minAbsDiff , Math.abs(arr[i]-arr[i+1]));
    }
    const ans:number[][]= [];
    
    for(let i : number =0 ;i<n-1;i++){
        if((arr[i+1]-arr[i])===minAbsDiff){
            ans.push([arr[i], arr[i+1]]);
        }
    }
    return ans ;
};