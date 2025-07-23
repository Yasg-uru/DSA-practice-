function missingNumber(nums: number[]): number {
   let actualsum=0;
   let expectedsum=0;
   for(let i=0;i<nums.length;i++){
    actualsum+=nums[i];

   }
   for(let i=1;i<=nums.length;i++){
    expectedsum+=i;
   } 
   return expectedsum-actualsum;
};