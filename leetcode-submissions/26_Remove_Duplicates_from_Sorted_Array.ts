function removeDuplicates(nums: number[]): number {
    let set=new Set(nums);
    let j=0;
    for(const ele of set){
nums[j++]=ele;
    }
    return j;
};