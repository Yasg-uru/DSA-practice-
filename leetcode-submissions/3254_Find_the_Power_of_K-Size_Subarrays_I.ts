function resultsArray(nums: number[], k: number): number[] {
    let n:number =nums.length;
    const ans:number[]= Array.from({length:n-k+1},()=>-1);
    let count:number =1;
    for(let i:number =1;i<k;i++){
        if(nums[i]===nums[i-1]){
            count++;
        }else{
            count=1;
        }
    }
    let i:number=1,j:number=k;
    while(j<n){
        if(nums[j]===nums[j-1]+1){
            count++;
        }else{
            count =1;
        }
        if(count>=k){
            ans[i]=nums[j];
        }
        i++;
        j++;
    }
return ans;
};