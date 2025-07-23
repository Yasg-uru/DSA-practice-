function reorderLogFiles(logs: string[]): string[] {
    const digits : string[]=[];
    const letters :string[]= [];
    function isDigit(word : string ):boolean{
        const temp = word.split(" ").slice(1).join(' ');
        return /\d/.test(temp[0]);
    }
    for(const log of logs){
        if(isDigit(log)){
            digits.push(log);
        }else{
            letters.push(log);
        }
        
    }
    letters.sort((a, b)=>{
       const [idA , ...Abody]= a.split(" ");
        const [idB , ...Bbody]= b.split(" ");
        const content_a = Abody.join(" ");
        const content_b = Bbody.join(" ");
        if(content_a===content_b){
            return idA.localeCompare(idB);
        }else{
            return content_a.localeCompare(content_b);
        }
    });
     return [...letters , ...digits];
    
};