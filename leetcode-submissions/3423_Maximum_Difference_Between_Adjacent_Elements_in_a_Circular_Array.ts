function maxAdjacentDistance(nums: number[]): number {
    const n : number = nums.length;
    let maxAbsDiff:number = Math.abs(nums[0]-nums[n-1]);
    for(let i:number =0;i<n-1;i++){
        maxAbsDiff = Math.max(maxAbsDiff, Math.abs(nums[i+1]-nums[i]));
    }
    return maxAbsDiff;
};