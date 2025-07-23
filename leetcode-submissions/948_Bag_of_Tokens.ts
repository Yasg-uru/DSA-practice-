function bagOfTokensScore(tokens: number[], power: number): number {
    tokens.sort((a, b)=>a-b);
    let i:number =0, j:number =tokens.length-1, maxScore:number = 0;
    let score:number =0;

    while(i<=j){
        if(power>=tokens[i]){
            power-=tokens[i];
            i++;
            score++;
            maxScore = Math.max(score , maxScore);
        }else if(score>0){
            power+=tokens[j];
            j--;
            score--;
        }else{
            break ;

        }
    }
    return maxScore ;
};