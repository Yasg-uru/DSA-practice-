function longestCommonPrefix(strs: string[]): string {
    strs.sort(a,b=>a-b);
    const str1=strs[0];
    const str2=strs[strs.length-1];
let j=0;

    for(let i=0;i<strs.length;i++){
        if(str1[i]===str2[i]){
            j++;
        }else{
            break;
        }
        return str1.slice(0,j);
    }
};