function findWords(words: string[]): string[] {
    const map:Map<string ,number>= new Map();
    const firstRow :string = "qwertyuiop";
    const secondRow:string = "asdfghjkl";
    const thridRow :string = "zxcvbnm";
    const ans:string[]= [];

    for(const character of firstRow){
        map.set(character , 1);
    }
    for(const character of secondRow){
        map.set(character , 2);
    }
    for(const character of thridRow){
        map.set(character , 3);

    }
    for(const word of words){
        const lowercaseWord= word.toLowerCase();
        const rowNumber : number = map.get(lowercaseWord[0]);
        let isPossible:boolean  = true ;
        for(let i:number = 1;i<lowercaseWord.length;i++){
            if(map.get(lowercaseWord[i])!==rowNumber){
                isPossible = false;
                break;
            }
            
        }
        if(isPossible){
            ans.push(word);
        }
    }
    return ans ;
};