function canReach(arr: number[], start: number): boolean {
    const n:number = arr.length;
    const dp :number[] = new Array(n+1).fill(-1);
    return solve(arr , start, n, dp );
};
function solve(arr:number[], i : number, n:number, dp:number[]):boolean{
    if(i<0  || i>=n || arr[i]===-1){
        return false;
    }
    if(arr[i]===0){
        return true ;
    }
    if(dp[i]!==-1){
        return dp[i]===1;
    }
    const jump : number = arr[i];
    arr[i] = -1;
    const take : boolean = solve(arr, i+jump,  n , dp);
    const not_take : boolean = solve(arr, i-jump, n , dp);
    const canGo:boolean = take || not_take ;
    dp[i]=  canGo?1:0;
    return canGo;

};