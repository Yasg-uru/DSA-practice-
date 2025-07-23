function minimumTime(grid: number[][]): number {
    if(grid[0][1]>1 && grid[1][0]>1){
        return -1;
    }
    const m:number =grid.length;
    const n:number =grid[0].length;
    const result:number[][]=Array.from({length:m},()=>Array.from({length:n},()=>Infinity));
    const pq:[number ,number,number][]=[];
    const push=(time:number ,row:number ,col:number):void=>{
        pq.push([time,row,col]);
        pq.sort((a,b)=>a[0]-b[0]);

    }
    result[0][0]=0;
    const directions :number[][]=[[0,1],[0,-1],[1,0],[-1,0]];
    const visited:boolean[][]=Array.from({length:m},()=>Array.from({length:n},()=>false));
    push(0,0,0);
    while(pq.length>0){
    const [time ,row,col]=pq.shift();
    pq.unshift();
    if(visited[row][col]){
        continue ;

    }
    if(row==m-1 && col==n-1){
        return result[m-1][n-1];

    }
    for(const dir of directions ){
        let i=row+dir[0];
        let j=col+dir[1];
        if(i<0 || j<0 || j>=n || i>=m){
            continue;

        }
        if(grid[i][j]<=time){
            push(time+1,i,j);
            result[i][j]=time+1;
        }else if ((grid[i][j]-time)%2===0){
            push(grid[i][j]+1,i,j);
            result[i][j]=grid[i][j]+1;
        }else {
            push(grid[i][j],i,j);
            result[i][j]=grid[i][j];

        }

    }


    }
    return result[m-1][n-1] ;


};