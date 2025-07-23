function minSubArrayLen(target: number, nums: number[]): number {
    let left =0;
    let right :number =0;
    let n :number =nums.length ;
    let minLength :number =Number.MAX_SAFE_INTEGER;


        let sum :number=0;
    while(right<n){
        sum+=nums[right];
        //adding value to the answer until the sum is exeeds 

        while ( sum>=target ){
            // need to add it to the answer and calculate the minans 
            sum-=nums[left];
            minLength=Math.min(minLength,right-left+1);
            left++;
        }
right ++;
    }
    return minLength===Number.MAX_SAFE_INTEGER?0:maxLength;
};