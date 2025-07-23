function canBeValid(s: string, locked: string): boolean {
    if(s.length%2){return false}// if string would be of odd length then we can't able to make string valid 

    let opening:number =0,closing:number =0,wildcard:number =0;

    for(let i:number =0;i<s.length;i++){
        if(locked[i]==="0") {
            wildcard++;
        } else if(s.charAt(i)==='('){
            opening++;
        }else {
            closing++;
        }
        if(wildcard<(closing-opening)){
            return false;
        }
    }
    opening=0;
    closing=0;
    wildcard=0;
    for(let i:number =s.length-1;i>=0;i--){
           if(locked[i]==="0") {
            wildcard++;
        } else if(s.charAt(i)==='('){
            opening++;
        }else {
            closing++;
        }
        if(wildcard<(closing-opening)){
            return false;
        }
    }
    return true;
};