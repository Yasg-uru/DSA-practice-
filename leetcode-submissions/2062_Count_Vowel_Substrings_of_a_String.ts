function countVowelSubstrings(word: string): number {
    const n:number = word.length;
    let ans : number =0 ;
    for(let i:number =0 ;i<n;i++){
        const map:Map<string , number> = new Map();
        for(let j =i ;j<n;j++){
            if(word[j]==="a" || word[j]==="i" || word[j]==="u" || word[j]==="e" || word[j]==="o" ){
                map.set(word[j], (map.get(word[j])! || 0)+1);

            }else{
                break;
            }
            if(map.size>=5){
                ans++;
            }
            
        }
    }
    return ans ;
};