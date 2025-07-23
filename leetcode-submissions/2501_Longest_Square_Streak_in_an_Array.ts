function longestSquareStreak(nums: number[]): number {
    let maxStreak=0;
    const mp=new Map<number ,number >();
    nums.sort((a,b)=>a-b);
    for(const n of nums ){
        //in this we need to find out the sqrt 
        const root:number =Number(Math.sqrt(n));
        if(root*root===n && mp.has(root)){
            mp.set(n,mp.get(root)+1);
        }else{
            mp.set(n,1);
        }
        maxStreak=Math.max(maxStreak,mp.get(n));
    }
    return maxStreak<2 ?-1:maxStreak;
};