function removeOuterParentheses(s: string): string {
    let ans:string="";
    const stack:string[]=[];
    for(let i=0;i<s.length;i++){
        if(s[i]=="("){
            if(stack.length>0){
                ans+="(";
            }
            stack.push("(");
        }else{
            stack.pop();
            if(stack.length>0){
                ans+=")";
            }
        }
    }
    return ans;
};