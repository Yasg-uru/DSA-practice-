function rangeSum(nums: number[], n: number, left: number, right: number): number {
    let arr:number[]=[];
    for(let i=0;i<nums.length;i++){
        let sum:number=0;
        for(let j=i;j<nums.length;j++){
            sum+=nums[j];
            arr.push(sum);
        }
    }
    arr.sort();
    let ans=0;

    for(let i=left-1;i<right;i++){
        ans=(ans+arr[i])% 1000000007;
    }
    return ans;

};