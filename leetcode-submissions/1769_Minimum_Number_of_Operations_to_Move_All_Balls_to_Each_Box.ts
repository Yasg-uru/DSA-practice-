function minOperations(boxes: string): number[] {
    const set:Set<number>=new Set();
    for(let i:number=0;i<boxes.length;i++){
        if(boxes[i]==="1") set.add(i);
    }
    const ans:number[]=Array.from({length:boxes.length},()=>0);
    for(let i:number =0;i<boxes.length;i++){
        let moves :number=0;
        for(const j of set){
            moves+=Math.abs(i-j);
        }
        ans[i]=moves;
    }
    return ans ;
};