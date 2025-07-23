function checkValidCuts(n: number, rectangles: number[][]): boolean {
    const x_axis :number[][]= [ ];
    const y_axis : number[][]= [];
    for(const [x1, y1 , x2, y2] of rectangles){
        x_axis.push([x1,x2]);
        y_axis.push([y1, y2]);
    }
    const merge_x:number[][] = merge(x_axis);
    const merge_y:number[][] = merge(y_axis);
    return merge_x.length>=3 || merge_y.length>=3;
};
function merge(intervals:number[][]){
    intervals.sort((a, b)=>a[0]-b[0]);
    const result:number[][]= [intervals[0]];
    for(let i:number=1;i<intervals.length;i++){
        const lastInterval = result[result.length-1];
        if(lastInterval[1]>intervals[i][0]){
            lastInterval[0] = Math.min(lastInterval[0], intervals[i][0]);
            lastInterval[1]= Math.max(lastInterval[1], intervals[i][1]);

        }else{
            result.push(intervals[i]);
        }
    }
    return result;
};