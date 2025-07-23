function numRescueBoats(nums: number[], limit: number): number {
    let i :number =0 , j:number = nums.length-1, ans:number =0 ;
    nums.sort((a, b)=>a-b);
    
    while(i<=j){
        // we have three cases 
        if(i==j && nums[i]<=limit){
            ans++;
            break;
        }else if(nums[i]+nums[j]<=limit){
            ans++;
            i++;
            j--;
        }else if(nums[i]+nums[j]>limit){
            ans++;
            j--;
        }else{
            break;
        }
    }
    return ans ;
};