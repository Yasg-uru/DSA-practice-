function minimumPushes(word: string): number {
    let ans:number=0;
    let cnt:number=1;
    const size:number=word.length;
    for(let i=0;i<size;i+=8){
        ans+=cnt*Math.min(8,size-i);
        cnt++;
    }
    return ans;
};