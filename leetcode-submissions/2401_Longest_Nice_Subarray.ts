function longestNiceSubarray(nums: number[]): number {
    // now we are optimizing our solution from o(n^2) to o(n)
    let i :number = 0 ;
    let j :number =  0 ;
    const n :number = nums.length;
    let mask:number =  0 ;
    let result :number = 1;


    while(j<n){

        while((mask & nums[j])!=0){
            mask = (mask ^ nums[i]);
            i++;
        }
        result = Math.max(result , j-i+1);
        mask = (mask | nums[j]);
        j++;
    }
    return result ;
};