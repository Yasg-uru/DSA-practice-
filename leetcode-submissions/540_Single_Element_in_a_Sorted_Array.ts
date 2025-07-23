function singleNonDuplicate(nums: number[]): number {
    const map:Map<number , number>= new Map();
    for(const n of nums){
        map.set(n, (map.get(n)! || 0 )+1);
    }
    for(const [key , value] of map.entries()){
        if(value===1){
            return key;
        }
    }
    return -1 ;
};