function distributeCandies(candyType: number[]): number {
    const mp:Map<number , number> = new Map();
    const n = candyType.length;
    for(const type of candyType){
        mp.set(type , (mp.get(type)! || 0 )+1);
    }
    const required = Math.floor(n/2) , types = mp.size;
    return Math.min(required   , types );
};