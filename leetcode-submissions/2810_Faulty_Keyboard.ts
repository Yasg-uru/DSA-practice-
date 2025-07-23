function finalString(s: string): string {
    let ans:string = "";
    for(const character of s){
        if(character==="i"){
            ans = ans.split("").reverse().join("");
            continue;
        }
        ans+=character;
    }
    return ans ;
};