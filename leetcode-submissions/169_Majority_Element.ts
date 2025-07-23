function majorityElement(nums: number[]): number {
    nums.sort();
    let n:number=nums.length;
    return nums[Math.floor(n/2)];
};