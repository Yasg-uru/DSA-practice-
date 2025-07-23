function canConstruct(s: string, k: number): boolean {
    if(s.length<k){
        return false;
    }
    const map:Map<string,number>=new Map();
    for(let i=0;i<s.length;i++){
        if(map.has(s[i])){
            map.set(s[i],map.get(s[i])+1);
        }else{
            map.set(s[i],1);
        }
    }
    let oddcount :number =0;
    for(const [key ,value] of map.entries()){
if(value%2===1){
    oddcount++;
}
    }
    return oddcount<=k;
};