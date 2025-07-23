function maximumSubarraySum(nums: number[], k: number): number {
    let i:number =0;
    let j:number =0;
    let result:number =0;

    const set=new Set<number>();
    let currentWindowSum:number =0;

    while(j<nums.length){
        while(set.has(nums[j])){
            set.delete(nums[i]);
            currentWindowSum-=nums[i];
            i++;
        }
        currentWindowSum+=nums[j];
        set.add(nums[j]);
        if(j-1+1===k){
            result=Math.max(result,currentWindowSum);
            currentWindowSum-=nums[i];
            set.delete(nums[i]);
            i++;
        }
        j++;

    }
    return result ;
};