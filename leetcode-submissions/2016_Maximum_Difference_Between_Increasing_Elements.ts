function maximumDifference(nums: number[]): number {
    let maxDiff : number = Number.MIN_SAFE_INTEGER;
    const n : number = nums.length ;

    for(let i:number =0 ;i<n;i++ ){
        for(let j:number =i+1;j<n;j++){
            maxDiff = Math.max(maxDiff , nums[j]-nums[i]);
        }
    }
    return maxDiff ;
};