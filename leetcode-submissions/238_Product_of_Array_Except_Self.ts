function productExceptSelf(nums: number[]): number[] {
    //brute force approach
    const ans:number[]=[];

    for(let i:number =0;i<nums.length;i++){
        let product:number =1;

        for(let j:number =0;j<nums.length;j++){
            if(i!==j){
                product*=nums[j];
            }
        }
        ans.push(product);
    }
    return ans ;
};