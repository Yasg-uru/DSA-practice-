function maxCount(banned: number[], n: number, maxSum: number): number {
    const s=new Set<number>(banned);
    let count :number=0,sum:number =0;

    for(let i:number =1;i<=n ;i++){
        if(! s.has(i) && sum+i<=maxSum){
            sum+=i;
            count++;
        }
    }
    return count;
};