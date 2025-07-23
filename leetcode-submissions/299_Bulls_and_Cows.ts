function getHint(secret: string, guess: string): string {
    let cows:number =0 , bulls : number =0,  n = guess.length ;
    const visited1:boolean[]= new Array(n).fill(false);
    const visited2:boolean[]= new Array(n).fill(false);
    for(let i:number=0 ;i<n;i++ ){
        if(secret[i]===guess[i]) {
            visited1[i]= visited2[i]= true ;
            bulls++;
        }
    }
    for(let i:number =0 ;i<n;i++){
        for(let j:number = 0;j<n;j++){
            if(visited1[i] || visited2[j] || i===j) continue ;
            if(secret[i]==guess[j]){
                cows++;
                  visited1[i]= visited2[j]= true ;
            }
        }
    }
    const ans :string = `${bulls}A${cows}B`;
return ans ;
};