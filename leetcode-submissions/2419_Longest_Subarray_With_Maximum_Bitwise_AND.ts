function longestSubarray(nums: number[]): number {
   let maxNumber:number=nums[0];
   for(const ele of nums){
   maxNumber=Math.max(ele,maxNumber);
   }
   let ans:number=0;
let cnt=0;
   for(const val of nums){
   if(val===maxNumber){
    cnt++;
   } else{
    cnt=0;
   }
   ans=Math.max(ans,cnt);
   }
   return ans;
};