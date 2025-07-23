function makeFancyString(s: string): string {
    const st:string[]=[];
    for(let i:number=0 ;i<s.length;i++){
        if(st.length>=2 && st[st.length-1]===s[i] && st[st.length-2]===s[i]){
            continue;
        }
        st.push(s[i]);
    }
    return st.join('');
};