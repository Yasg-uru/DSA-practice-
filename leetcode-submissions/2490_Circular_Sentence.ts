function isCircularSentence(sentence: string): boolean {
    // we need to split the word by the spaces 
    const words:string[]=sentence.split(" ");
    //after that we need to check whether the string will matching the second condition or not 
    if(words[0].charAt(0)!==words[words.length-1].charAt(words[words.length-1].length-1)){
        return false;
    }
    for(let i:number=0;i<words.length-2;i++){
        if(words[i].charAt(words[i].length-1)!==words[i+1].charAt(0)){
            return false;
        }
    }
    return true ;
};