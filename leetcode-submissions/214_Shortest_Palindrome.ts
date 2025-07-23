function shortestPalindrome(s: string): string {
    let i:number=0;
    for(let j=s.length-1;j>=0;j--){
        if(s.charAt(i)===s.charAt(j)){
            i++;
        }
    }
    if(i===s.length){
        return s;
    }
    let p:string=s.split("").slice(i).reverse().join("");
    return p+shortestPalindrome(s.split("").slice(0,i).join(""))+s.split("").slice(i).join("");

};