function reverseWords(s: string): string {
    let arr:string[]=s.trim().split(/\s+/);
    arr=arr.reverse();
    
    return arr.join(" ");

    

};