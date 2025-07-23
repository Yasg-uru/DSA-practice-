function sortArrayByParity(nums: number[]): number[] {
    const ans:number[] = [];
    for(const num of nums){
        if(num%2===0){
        ans.push(num);
        }
    }
    for(const num of nums){
    if(num%2===1){
        ans.push(num);
    }
    }
    return ans ;
};