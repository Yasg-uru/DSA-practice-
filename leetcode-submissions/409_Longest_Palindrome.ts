function longestPalindrome(s: string): number {
    const map:Map<string,number >=new Map();
    for(const character of s){
        if(map.has(character)){
            map.set(character,map.get(character)+1);
        }else {
            map.set(character,1);
        }
    }
    let ans :number =0;
    let oddcount:number =0;

    for(const [character,frequency] of map.entries()){
        if(frequency%2===0){
            ans+=frequency;
        }else {
            oddcount++;
        }
    }
    if(oddcount>1){
return (s.length-oddcount)+1;
    }
    return s.length;
};