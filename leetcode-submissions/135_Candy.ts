function candy(ratings: number[]): number {
    //now i am solving this question by using the greedy approach
    const n:number=ratings.length;
    const left:number[]=Array.from({length:n}).fill(1) as number[];
    const right:number[]=Array.from({length:n}).fill(1) as number[];
    //after this we need to calculate this right and left 
    for(let i=1;i<n;i++){
        if(ratings[i-1] <ratings[i]){
            left[i]=left[i]+1;
        }
    }
    for(let i=n-2;i>=0;i--){
        if(ratings[i+1] <ratings[i]){
right[i]=right[i]+1;
        }
    }
    let ans :number =0;
    for(let i=0;i<n;i++){
        ans+=Math.max(right[i],left[i]);
    }
    return ans;
};