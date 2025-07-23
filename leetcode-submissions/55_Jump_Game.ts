function canJump(nums: number[]): boolean {
    let farthest:number =nums[0] ;

    for(let i:number =1 ;i<nums.length;i++){
        if(farthest<i){
            return false;
        }
        farthest = Math.max(farthest, nums[i]+i);
    }
    return  true ;
};