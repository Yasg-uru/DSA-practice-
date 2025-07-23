function areSentencesSimilar(sentence1: string, sentence2: string): boolean {
    if(sentence1.length>sentence2.length){
        return areSentencesSimilar(sentence2,sentence1);
    }
    const s1:string[]=sentence1.split(" ");
    const s2:string[]=sentence2.split(" ");
    let start=0,end1=s1.length,end2=s2.length;
    while(start<=end1 && s1[start]===s2[start]){
        start++;
    }
    while(start<=end1 && s1[end1]===s2[end2]){
        end1--;
        end2--;
    }
    //if the start is crossed by the end then return true 
    return (start>end1);
};