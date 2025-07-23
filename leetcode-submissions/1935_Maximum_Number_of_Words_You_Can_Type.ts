function canBeTypedWords(text: string, brokenLetters: string): number {
    const lookUp:Set<string>= new Set(brokenLetters.split("").map((l)=>l));
    const arr:string[]= text.split(" ");
    let ans : number =0 ;
    for(const word of arr){
        let isPossible:boolean = true ;
        for(const ch of word){
           if(lookUp.has(ch)){ isPossible = false;
            break ;}
        }
        if(isPossible){
            ans++;
        }
        
    }
    return ans ;
};