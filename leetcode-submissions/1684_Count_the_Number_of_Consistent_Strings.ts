function countConsistentStrings(allowed: string, words: string[]): number {
let ans:number=0;
const unique=new Set(allowed);
for(const word of words){
    const wordArr=word.split('');
    let flag:boolean=true;
    for(let i=0;i<wordArr.length;i++){
        if(!unique.has(wordArr[i])){
            flag=false;
            break;

        }
    }
    if(flag){
        ans+=1;
    }

}
return ans;
};