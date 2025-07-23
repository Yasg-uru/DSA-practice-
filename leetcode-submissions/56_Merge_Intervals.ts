function merge(intervals: number[][]): number[][] {
    //this question is solved by the greedy algorithm 
    intervals.sort((a,b)=>a[0]-b[0]);
    //after that we need to declare the start and end 
    let start:number =intervals[0][0];
    let end:number=intervals[0][1];
    const ans:number[][]=[];
    for(let i=1;i<intervals.length;i++){
        if(end>=intervals[i][0]){
            // we need to merge it 
            end=Math.max(end,intervals[i][1]);
        }else{
ans.push([start,end]);
start=intervals[i][0];
end=intervals[i][1];
        }
    }
    ans.push([start,end]);
    return ans ;
};