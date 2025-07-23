function waysToSplitArray(nums: number[]): number {
    const prefixSum:number[]=Array.from({length:nums.length},()=>0);
    const suffixSum:number[]=Array.from({length:nums.length},()=>0);
    prefixSum[0]=nums[0];
    suffixSum[nums.length-1]=nums[nums.length-1];

    for(let i=1;i<nums.length;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    for(let i=nums.length-2;i>=0;i--){
        suffixSum[i]=suffixSum[i+1]+nums[i];
    }
    let count =0;
    for(let i:number =0;i<prefixSum.length;i++){
        if(prefixSum[i]>=suffixSum[i+1]){
            count ++;
        }
    }
    return count ;

};