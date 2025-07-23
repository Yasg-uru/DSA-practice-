function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const ans :Set<number> = new Set(), n :number=nums.length;
    for(let i:number =0 ;i<n;i++){
        for(let j=0;j<n;j++){
            if(Math.abs(i-j)<=k && nums[j]===key){
                ans.add(i);
            }
        }
    }
    
    return [...ans] ;

};