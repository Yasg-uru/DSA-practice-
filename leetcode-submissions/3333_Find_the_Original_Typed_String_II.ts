function possibleStringCount(word: string, k: number): number {
    if(word.length<k){
        return 0 ;
    }
    const freq:number[]= [];
    let count:number =1;
    for(let i:number = 1;i<word.length;i++){
        if(word[i]===word[i-1]){
            count++;
        }else {
            freq.push(count);
            count = 1;
        }
    }
    freq.push(count);
    let Possibilities :number=1;
    const MOD = (1e9+7);
    for(const f of freq){
        Possibilities = (Possibilities*f)%MOD;
    }

    if(freq.length>=k){
        return Possibilities%MOD;// return all possiblities
    }
 const dp: number[][] = Array.from({ length: freq.length + 1 }, () =>
  new Array(k + 1).fill(-1)
);

    const inValidStringCounts :number = solve(freq , 0 , 0, k, dp ); 

    return (Possibilities-inValidStringCounts);
};
function solve(freq:number[], i :number , count:number,k:number, dp:number[][]){
    const n :number = freq.length;
     const MOD = (1e9+7);
    if(i>=n){
        return (count<k)?1:0; // if the count is less than the k then one invalid frequency is found 

    }
    if(dp[i][count]!==-1){
        return dp[i][count];
    }
    let invalidCount :number =0 ;
     // now we have a choice to take the frequencies of the current character 
     for(let take:number = 1;take<=freq[i];take++){
        if((take+count)<k){
            invalidCount= (invalidCount +solve(freq , i+1, count+take, k, dp))%MOD;
        }else {
            break ;
        }
     }
     return dp[i][count]=  invalidCount ;

}