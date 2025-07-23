function getEncryptedString(s: string, k: number): string {
    // so our approach is very simple in which we need to use the modulel operation only 
    let str:string =""
    for(let i:number =0;i<s.length;i++){
        str+=s[(i+k)%s.length];

    }
    return str;
};