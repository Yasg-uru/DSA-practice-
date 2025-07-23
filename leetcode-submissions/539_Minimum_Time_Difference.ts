function findMinDifference(timePoints: string[]): number {
   const times:number[]=timePoints.map(time=>{
    const [hrs,minute]=time.split(":");
    return parseInt(hrs)*60+parseInt(minute);
   });
   times.sort();
   let minDiff:number=Number.MAX_SAFE_INTEGER;
   for(let i=0;i<times.length-1;i++){
minDiff=Math.min(minDiff,times[i+1]-times[i]);


   } 
minDiff=Math.min(minDiff,1440+times[0]-times[times.length-1]);
return minDiff;
};