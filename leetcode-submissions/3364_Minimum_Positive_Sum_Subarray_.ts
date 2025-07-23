function minimumSumSubarray(nums: number[], l: number, r: number): number {
    let i :number =0,j:number =0, minSum :number = Number.MAX_SAFE_INTEGER, sum:number =0;
    const n:number =nums.length;
    while(j<n){
        sum+=nums[j];
        while((j-i+1)>r){
            sum-=nums[i];
            i++;
        }
        if((j-i+1)>=l){
            minSum = Math.min(minSum , sum);
        }
        j++;

    }
    return (minSum== Number.MAX_SAFE_INTEGER || minSum<0)?-1:minSum;
};