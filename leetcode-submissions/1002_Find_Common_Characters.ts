function commonChars(words: string[]): string[] {
   //efficient approach is this to calculate the frequency of each character and just compare it with the length of the array of the words if yes then add it to the answer 
   const minansFreq:number[]=Array.from({length:26},()=>Number.MAX_SAFE_INTEGER);

   const ans:string[]=[];
   for(let i=0;i<words.length;i++){
   const freq:number[]=Array.from({length:26},()=>0);
    for(let j=0;j<words[i].length;j++){
        let index:number =words[i].charCodeAt(j);
        freq[index-97]++;

    }
    // in every insertion we need to calculate the minimum frequency of the character 
    for(let i=0;i<26;i++){
        minansFreq[i]=Math.min(minansFreq[i],freq[i]);
    }
   }
   for(let i:number =0;i<26;i++){
    const character:string =String.fromCharCode(i+97);
    while(minansFreq[i]>0){
        ans.push(character);
        minansFreq[i]--;
    }
   }
   return ans;
};