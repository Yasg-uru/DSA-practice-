function singleNumber(nums: number[]): number {
    let map=new Map<number,number>();
    for(const ele of nums){
        if(!map.has(ele)){
            map.set(ele,1);
        }else{
            map.set(ele,map.get(ele)+1);
        }
    }
    for(const [key,value] of map.entries()){
        if(value===1){
            return key;
        }
    }
return -1;
};