function countPalindromicSubsequence(s: string): number {
    const letters:Set<string>=new Set(s);
    let count:number =0;
    for(const letter of letters){
        const firstIndex=s.indexOf(letter);
        const lastIndex=s.lastIndexOf(letter);
        const chars:Set<string>=new Set();
        for(let i:number=firstIndex+1;i<lastIndex;i++)
        {
            chars.add(s[i]);
        }
        count+=chars.size;

    }
return count;
};