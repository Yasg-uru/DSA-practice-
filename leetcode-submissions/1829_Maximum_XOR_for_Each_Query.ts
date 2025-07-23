function getMaximumXor(nums: number[], maximumBit: number): number[] {
    const result:number[] =[];
    let XOR=0;

    for(const ele of nums){
XOR^=ele;
    }
    let mask=((1<<maximumBit)-1);
    for(let i=0;i<nums.length;i++){
        let k=XOR^mask;
        result.push(k);
        XOR=(XOR^nums[nums.length-1-i]);
    }
    return result;
};