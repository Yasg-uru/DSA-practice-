function minimumPushes(word: string): number {
    let freq:number[]=Array(26).fill(0);
    for(const ch of word){
         const index = ch.charCodeAt(0) - 'a'.charCodeAt(0);
        freq[index]=freq[index]===0?1:freq[index]+1;
    }
    freq.sort((a,b)=>b-a);
    let ans:number=0;

    for(let i=0;i<26;i++){
        if(i<8){
            ans+=freq[i];
       }else if(i<16){
        ans+=freq[i]*2;

       }else if(i<24){
        ans+=freq[i]*3;
       }else{
        ans+=freq[i]*4;
       }
    }
    return ans;
};