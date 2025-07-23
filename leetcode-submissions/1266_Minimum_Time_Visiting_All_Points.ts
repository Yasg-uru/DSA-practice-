function minTimeToVisitAllPoints(points: number[][]): number {
    let ans : number =0, n :number = points.length ;
    for(let i:number =1 ;i<n;i++){
        const dx = Math.abs(points[i][0]-points[i-1][0]);
        const dy = Math.abs(points[i][1]-points[i-1][1]);
        ans+=Math.max(dx, dy);
    }
    return ans ;
};