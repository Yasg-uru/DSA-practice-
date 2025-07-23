function returnToBoundaryCount(nums: number[]): number {
    const n:number = nums.length;
    let sum : number =0, ans:number =0  ;
    for(let i:number =0 ;i<n;i++){
        sum+=nums[i];
        if(sum === 0 ){
            ans++;
        }
    }
    return ans ;
};