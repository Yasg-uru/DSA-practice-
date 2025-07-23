/**
 Do not return anything, modify nums in-place instead.
 */
 
function moveZeroes(nums: number[]): void {
   let z_count=0;
   for(let i=0;i<nums.length;i++){
    if(nums[i]===0){
        z_count++;
        nums.splice(i,1);
    }
   }
   while(z_count--){
    nums.push(0);
   }
};