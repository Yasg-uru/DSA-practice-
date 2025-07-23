function maxValue(events: number[][], k: number): number {
    events.sort((a, b)=>a[0]-b[0]);
    const dp:number[][]= new Array(events.length+1).fill(0).map(()=>new Array(k+1).fill(-1));
    return solve(events , k , 0, dp );
};
function getIndex(events : number[][], lastPickedEnd : number):number{
    const n:number = events.length;
    let index:number = n , left : number =0 , right : number = events.length-1;
    while(left<=right){
        const Mid: number = Math.floor((left+right)/2);
        if(events[Mid][0]>lastPickedEnd){
            index = Mid ;
            right = Mid-1;
        }else{
            left = Mid+1;
        }
    }
    return index ;
}
function solve(events:number[][] , k:number, i :number,dp:number[][]):number{
    const n: number = events.length;
    if(i>=n || k===0){
        return 0 ;
    }
    if(dp[i][k]!==-1){
        return dp[i][k];
    }

    const take : number = events[i][2]+solve(events , k-1, getIndex(events, events[i][1]), dp);
    const not_take : number = solve(events , k, i+1, dp);
    return dp[i][k] =  Math.max(take  , not_take);

}