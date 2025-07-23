function is_sorted(nums:number[]):boolean{
   
    for(let i=0;i<nums.length-1;i++){
        if(nums[i]>nums[i+1]){
            return false;
        }
    }
    return true;
}
function check(nums: number[]): boolean {
    let cnt=0;
if(is_sorted(nums)){
    return true;
}
if(nums[0]<nums[nums.length-1]){
    return false;
}
    for(let i=0;i<nums.length-1;i++){
        if(nums[i]>nums[i+1]){
            cnt++;
            if(cnt>1){
                return false;
            }
        }


    }
    return cnt<=1;
};