function minimumIndex(nums: number[]): number {
    const firstMap:Map<number , number>= new Map();
    const secondMap:Map<number, number>= new Map();
    const n : number = nums.length;
    for(const num of nums){
        secondMap.set(num, (secondMap.get(num) || 0)+1);
    }
    for(let i : number = 0 ;i<n;i++){
        const num : number = nums[i];
        firstMap.set(num ,(firstMap.get(num) || 0)+1);
        secondMap.set(num , (secondMap.get(num) || 0)-1);
        if(firstMap.get(num)!*2>i+1 && secondMap.get(num)!*2>n-i-1){
            return i ;
        }
    }
    return -1;

};