function maximumBeauty(nums: number[], k: number): number {
    const intervals:{start:number ;end:number }[]=[];
    for(let i:number=0;i<nums.length;i++){
        intervals.push({start:nums[i]-k,end:nums[i]+k});

    }
    //after this we need to sort this in ascending order 
    intervals.sort((a,b)=>a.start-b.start);
    const queue:number[]=[];
    let maxBeauty:number =1;
    for(let i:number =0;i<intervals.length;i++){
        while(queue.length>0 && queue[0]<intervals[i].start){
            queue.shift();

        }
        queue.push(intervals[i].end);
        maxBeauty=Math.max(maxBeauty,queue.length);


    }
    return maxBeauty;

};