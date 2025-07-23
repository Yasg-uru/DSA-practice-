function buttonWithLongestTime(events: number[][]): number {
    
    let maxTimeTaken :number =events[0][1], minIndex:number = events[0][0];
    
    for(let i=1;i<events.length;i++){
        const timeTaken = events[i][1]-events[i-1][1];
       if(maxTimeTaken<timeTaken){
        maxTimeTaken = timeTaken;
        minIndex = events[i][0];
       }else if (maxTimeTaken===timeTaken && minIndex>events[i][0]){
        minIndex = events[i][0];
       }
    }
    return minIndex ;
};