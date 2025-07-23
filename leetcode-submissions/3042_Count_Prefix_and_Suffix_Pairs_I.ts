function countPrefixSuffixPairs(words: string[]): number {
    let ans:number =0;

    for(let i:number =0;i<words.length;i++){
        for(let j:number =i+1;j<words.length;j++){
            if(isPrefixAndSuffix(words[i],words[j])){
                ans+=1;

            }
        }
    }
    return ans;
};
function isPrefixAndSuffix(str1:string ,str2:string):boolean{
    let startIndex=str2.indexOf(str1);
    let lastIndex=str2.lastIndexOf(str1);
    if(startIndex===lastIndex){
        return false ;
    }
    return startIndex!==-1 && lastIndex!==-1;
}