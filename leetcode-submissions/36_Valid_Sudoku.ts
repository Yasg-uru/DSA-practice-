function isValidSudoku(board: string[][]): boolean {
    for(let i:number =0 ;i<9;i++){
    const st : Set<string > = new Set();
        for(let j:number =0 ;j<9;j++){
             if(board[i][j]=== ".") continue ;
            if(st.has(board[i][j])){
                return false;
            }
            st.add(board[i][j]);
        }

    }

        for(let j:number =0 ;j<9;j++){
    const st : Set<string > = new Set();
     for(let i:number =0 ;i<9;i++){
         if(board[i][j]=== ".") continue ;
            if(st.has(board[i][j])){
                return false;
            }
            st.add(board[i][j]);
        }

    }
    const coords:[number, number][][] = [
    [ [0, 0], [2, 2] ], [ [0, 3], [2, 5] ], [ [0, 6], [2, 8] ],
    [ [3, 0], [5, 2] ], [ [3, 3], [5, 5] ], [ [3, 6], [5, 8] ],
    [ [6, 0], [8, 2] ], [ [6, 3], [8, 5] ], [ [6, 6], [8, 8] ]
    ];

    for(const [[s_i, s_j] , [e_i, e_j]] of coords){
        if(check(s_i , s_j , e_i, e_j, board) === false){
            return false;
        }
    }
    return true ;

};
function check(si:number , sj:number , ei:number , ej:number, board:string[][]):boolean{
    const st:Set<string> = new Set();
    for(let i:number = si;i<=ei;i++){
        for(let j:number = sj;j<=ej;j++){
            if(board[i][j]=== ".") continue ;
            if(st.has(board[i][j])){
                return false;
            }
        }
    }
    return true ;
}