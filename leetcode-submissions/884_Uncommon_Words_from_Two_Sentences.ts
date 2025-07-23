function uncommonFromSentences(s1: string, s2: string): string[] {
    const s1Array:string[]=s1.split(" ");
    const s2Array:string[]=s2.split(" ");
    const mp1=new Map<string,number>();
    const mp2=new Map<string,number>();
    for(let i=0;i<s1Array.length;i++){
        if(mp1.has(s1Array[i])){
            mp1.set(s1Array[i],mp1.get(s1Array[i])+1);
        }else{
            mp1.set(s1Array[i],1);
        }
         
    }
    for(let i=0;i<s2Array.length;i++){
        if(mp1.has(s2Array[i])){
            mp1.set(s2Array[i],mp1.get(s2Array[i])+1);
        }else{
            mp1.set(s2Array[i],1);
        }
         
    }
    const ans:string[]=[];
    for(const [key,value] of mp1.entries()){
        if(value===1){
            ans.push(key);
        }
    }
    
    return ans;
};