function summaryRanges(nums: number[]): string[] {
   const consecutive_groups :number[][] = [], arr:number[] =[];
   const n:number = nums.length;

   for(let i:number =0 ;i<n;i++){
    if(arr.length ===  0 || arr[arr.length-1]+1 === nums[i]){
        arr.push(nums[i]);
    }else{
        consecutive_groups.push([...arr]);
        arr.length =0 ;
        arr.push(nums[i]);
    }
   }
     if (arr.length > 0) {
        consecutive_groups.push([...arr]);
    }
   const ans : string[] = [];
   console.log(consecutive_groups);
   // now the array is consecutive sorted groups 
   for(const arr of consecutive_groups){
    if(arr.length===1){
        ans.push(arr[0].toString());
    }else{
        
        ans.push(`${arr[0]}->${arr[arr.length-1]}`);
    }
   }
   return ans ;
};