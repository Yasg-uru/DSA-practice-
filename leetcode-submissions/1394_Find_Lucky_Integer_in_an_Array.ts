function findLucky(arr: number[]): number {
    const mp:Map<number , number> = new Map();
    for(const num of arr){
        mp.set(num , (mp.get(num)! || 0)+1);
    }
    let maxAns : number = Number.MIN_SAFE_INTEGER;
    for(const [key , value] of mp.entries()){
        if(key===value){
            maxAns = Math.max(maxAns , key);
        }
    }
    return (maxAns===Number.MIN_SAFE_INTEGER)?-1:maxAns  ;
};