function countServers(grid: number[][]): number {
let resultantServers:number =0;
let m:number =grid.length;
let n:number =grid[0].length;
for(let i:number=0;i<m;i++)
{
    for(let j:number =0;j<n;j++){
        if(grid[i][j]==1){
            let isAnotherServer:boolean =false;
            //check in the row 
            for(let row:number =0;row<m;row++){
                if(row!==i && grid[row][j]===1){
                    isAnotherServer=true;
                    break;
                }
            }
            if(isAnotherServer){
                resultantServers++;
                continue;
            }
            for(let col:number =0;col<n;col++){
                if(col!==j && grid[i][col]===1){
                    isAnotherServer=true;
                    break;
                }
            }
            if(isAnotherServer){
                resultantServers++;
            }
        }
    }
}
return resultantServers++;

};
