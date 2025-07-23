function rearrangeArray(nums: number[]): number[] {
    const negative:number[]=[];
    const positive:number[]=[];
    for(const ele of nums){
        if(ele<0){
            negative.push(ele);
        }else{
            positive.push(ele);

        }
    }
    let i:number=0;
    const ans:number[]=[];

    while(i<positive.length){
        ans.push(positive[i]);
        ans.push(negative[i]);
        i++;
    }
    return ans;
};