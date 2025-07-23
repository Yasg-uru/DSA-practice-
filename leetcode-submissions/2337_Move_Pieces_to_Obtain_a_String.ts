function canChange(start: string, target: string): boolean {
    // we need to create two pointers 
    let i:number =0;
    let j:number =0;
    let n:number =start.length ;
    while(i<n || j<n ){
        while(start[i]==="_" && i<n) i++;
        while(target[j]=="_" && j<n) j++;
        if(start[i]!==target[j]) return false ;
        if(start[i]==="L" && i<j) return false ;
        if(start[i]==="R" && i>j) return false ;
        if(i===n || j===n) return i===n && j===n;
        i++;
        j++;
    }
    return true ;
};