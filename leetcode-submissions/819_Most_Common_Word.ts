function mostCommonWord(paragraph: string, banned: string[]): string {
  const map:Map<string , number>= new Map(); //storing all the lowercae strings frequencies 
    const isBanned:Set<string>= new Set(banned.map(word=>word.toLowerCase()));
    const words :string[] = paragraph.toLowerCase().match(/\w+/g) || [];
    for(const word of  words ){
      if(!isBanned.has(word)){
            map.set(word, (map.get(word)! || 0)+1);
      }
    }
   let maxFreq :number = -1 , maxFreqWord :string = "";
    for(const [word , freq] of map.entries()){
        if(maxFreq<freq){
            maxFreq = freq;
            maxFreqWord = word;
        }
    }
    return maxFreqWord ;
};