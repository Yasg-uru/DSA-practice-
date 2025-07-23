function isArraySpecial(nums: number[], queries: number[][]): boolean[] {
    const breaks:number[]=new Array(nums.length).fill(0);
    const prefix:number[]=new Array(nums.length).fill(0);
    const ans:boolean[]=[];
    for(let i:number=0;i<nums.length-1;i++){
breaks[i]=(Math.floor(nums[i]%2)===Math.floor(nums[i+1]%2))?1:0;
    }
    prefix[0]=breaks[0];
    for(let i:number =1;i<breaks.length;i++){
        prefix[i]=prefix[i-1]+breaks[i];
    }
    for(const query of queries){
        const[start,end]=query;
        if(start===end){
ans.push(true);
        }else if((prefix[end]-prefix[start])===0){
ans.push(true);
        }else {
ans.push(false);
        }

    }
    return ans ;
};