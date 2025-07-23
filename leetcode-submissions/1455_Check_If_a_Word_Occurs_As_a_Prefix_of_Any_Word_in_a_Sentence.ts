function isPrefixOfWord(sentence: string, searchWord: string): number {
    const arr:string[]=sentence.split(" ");
    for(let i:number =0;i<arr.length;i++){
        if(is_found(arr[i],searchWord)){
            return i+1;
        }

    }
    return -1;
};
function is_found(word:string , prefix:string):boolean{
    let temp:string ="";
    for(const ch of word){
        temp+=ch;
        if(temp===prefix){
            return true ;

        }
    }
    if(temp==prefix){
        return ;
    }
    return false;
}