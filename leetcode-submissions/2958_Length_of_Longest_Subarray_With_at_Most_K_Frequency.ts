function maxSubarrayLength(nums: number[], k: number): number {
    let i :number = 0 , j:number = 0 , maxAns :number = 0;
    const n  : number = nums.length;
    const mp:Map<number , number > = new Map();

    while(j<n){
        mp.set(nums[j], (mp.get(nums[j]) || 0) + 1);
        while(mp.get(nums[j])>k){
            mp.set(nums[i], (mp.get(nums[i]) ||  0 )-1);
            i++;
        }

        maxAns = Math.max(maxAns, j-i+1);
        j++;

    }
    return maxAns;
};