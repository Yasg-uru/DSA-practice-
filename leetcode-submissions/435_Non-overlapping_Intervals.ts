function eraseOverlapIntervals(intervals: number[][]): number {
    intervals.sort((a,b)=>a[1]-b[1]);
    //after this we need to track of lastend 
    let lastend:number=intervals[0][1];
    let count =0;
    for(let i=1;i<intervals.length;i++){
        if(intervals[i][0]<lastend){
            count++;
        }else{
            lastend=intervals[i][1];

        }
    }
    return count;
};