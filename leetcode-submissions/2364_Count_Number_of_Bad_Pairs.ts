function countBadPairs(nums: number[]): number {
    const mp:Map<number,number>=new Map();
    let totalPairs:number =0;
    mp.set(nums[0],1);
    for(let j:number =1;j<nums.length;j++){
        const currentNumsCount :number = mp.get(nums[j]-j) || 0 ;
        const numsBeforeJ:number = j;
        const badPairs:number = numsBeforeJ-currentNumsCount;
        totalPairs+=badPairs;
        mp.set(nums[j]-j, (mp.get(nums[j]-j) || 0)+1);

    }
    return totalPairs;
};