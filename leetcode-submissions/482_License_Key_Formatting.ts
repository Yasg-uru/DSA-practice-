function licenseKeyFormatting(s: string, k: number): string {
    let str :string = "";
    for(const character of s){
        if(character==="-") continue;
        str+=character.toUpperCase();
    }
    console.log("this is str :;", str)
    const n :number = str.length;
    let result:string = "", count :number = 0 ;
    
    for(let i:number = n-1;i>=0;i--){
       result = str[i]+result;
        count++;
        if(count==k || i==0){
            result = "-"+result;
            count =0 ;
            
        }
        
    }
    console.log("this is ans :", result )
    
    return result.slice(1)  ;
};