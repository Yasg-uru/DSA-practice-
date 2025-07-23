function numMatchingSubseq(s: string, words: string[]): number {
    let count : number  =0 ;
    for(const word of words){
        const dp:Map<string , boolean>= new Map();
        count+=(solve(s , word , s.length, word.length, 0 , 0, dp)===true?1:0);
    }
    return count ;
};
function solve(s:string , word:string , m :number , n :number, i:number , j:number, dp:Map<string , boolean>):boolean{
    if(i==n){
        return true ;
    }
    if(j==m){
        return false;
    }
    const key :string = `${i}-${j}`;
    if(dp.has(key)){
        return dp.get(key);
    }
    let currAns :boolean = false;
    if(s[j]==word[i]){
    currAns =    solve(s, word , m , n , i+1, j+1, dp);
    }
    if(currAns===true){
        return true ;
    }

    currAns = solve(s, word , m , n ,i, j+1, dp );
    dp.set(key , currAns );
    return  currAns ;
}