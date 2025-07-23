function tupleSameProduct(nums: number[]): number {
    const mp:Map<number,number>=new Map();
    for(let i:number =0;i<nums.length-1;i++){
        for(let j:number =i+1;j<nums.length;j++){
            mp.set(nums[i]*nums[j], (mp.get(nums[i]*nums[j]) || 0)+1);
        }

    }
    let count:number =0;
    for(const [product, freq] of mp.entries()){
if(freq>1){
count+=(8*nc2(freq));
}
    }
    return count;
};
const nc2=(n:number):number=>n*(n-1)/2;