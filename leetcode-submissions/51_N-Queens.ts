function solveNQueens(n: number): string[][] {
    const ans : string[][] =[];
    const board:string[] =  Array.from({length:n}, ()=>".".repeat(n));
    function checkSameRow(row:number, col:number):boolean{
        for(let i =row-1 ;i>=0;i--){
            if(board[i][col]==='Q'){
                return true;
            }
        }
        return false;
    }   
    function checkDiagonals(row:number , col:number):boolean{
        for(let i = row-1, j= col-1;i>=0 && j>=0 ; i--, j--){
            if(board[i][j]==='Q'){
                return true ;
            }
        }
        for(let i= row-1, j= col+1;i>=0 && j<n ; j++,i--){
            if(board[i][j]==='Q'){
                return true ;
            }
        }
        return false;
    };

    function bracktracking(i:number):void{
        if(i==n){
            ans.push([...board]);
            return ;
        }
        for(let j =0;j<n;j++){
            //check we can assign or not 
            if(!checkSameRow(i , j) && !checkDiagonals(i , j)){
                let rowArr = board[i].split("");
                rowArr[j]="Q";
                board[i] = rowArr.join("");
                bracktracking(i+1);
               rowArr[j]=".";
                board[i] = rowArr.join("");
            }
        }
        //do 

        //explore

        //undo
    }
    bracktracking(0);
    return ans ;
};

