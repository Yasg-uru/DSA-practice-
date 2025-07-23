function numIslands(grid: string[][]): number {
    let m :number = grid.length , n:number = grid[0].length;
    const visited:boolean[][]=Array.from({length:m},()=>Array.from({length:n},()=>false));
    const directions :[number,number][]=[[0,1],[0,-1],[-1,0],[1,0]];

    
    let cc:number =0;

    for(let i:number =0;i<m;i++){
        for(let j:number =0;j<n ;j++){
            if(grid[i][j]==="1" && !visited[i][j]){
                const  queue:[number,number][]=[[i,j]];//to store the coordinates 
                visited[i][j]=true;
                while(queue.length>0){
                    const [row ,col]=queue.shift()!;
                    for(const dir of directions){
                        const i_:number = dir[0]+row;
                        const j_:number =dir[1]+col;
                        if(i_>=0 && j_>=0 && j_<n && i_<m && !visited[i_][j_] && grid[i_][j_]==="1"){
                            queue.push([i_,j_]);
                            visited[i_][j_]=true;
                        }
                    }
                }
                cc++;
            }
        }
    }
    return cc;

};