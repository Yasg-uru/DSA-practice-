function isArraySpecial(nums: number[]): boolean {
     const n:number =nums.length;
    //  nums.sort((a,b)=>a-b);
     for(let i:number =1;i<n;i++){
        if(nums[i-1]%2===nums[i]%2){
            return false;
        }
     }
     return true;
};