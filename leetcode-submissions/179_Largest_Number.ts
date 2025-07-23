function largestNumber(nums: number[]): string {
    nums.sort((a,b)=>(b.toString()+a.toString()).localeCompare(a.toString()+b.toString()) );
    let ans:string="";
    for(const ele of nums){
        ans+=ele.toString();
    }
    return ans.charAt(0)==="0"?"0":ans;
};