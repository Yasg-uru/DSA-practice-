function answerString(word: string, numFriends: number): string {
    const n:number =word.length;

    const gap:number = n-numFriends+1;
    let ans : string = "";
    for(let i:number=0 ;i<n-gap;i++){
        const str  = word.substring(i , i+gap);
        ans= ans>str ?ans :str;
    } 
    return ans ;
};