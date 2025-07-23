function partitionArray(nums: number[], k: number): number {
    nums.sort((a, b)=>a-b);
    let count : number =1 , minVal :number = nums[0];
    for(let i:number = 1;i<nums.length;i++){
        if((nums[i]-minVal)>k){
            minVal= nums[i];
            count++;
        }
    }
    return count ;
};