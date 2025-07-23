function possibleStringCount(word: string): number {
    let count :number =1;
    for(let i:number =1 ;i<word.length;i++){
        if(word[i]===word[i-1]){
            count++;
        }
    }
    return count ;
};