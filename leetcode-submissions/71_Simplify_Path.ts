function simplifyPath(path: string): string {
    const stack:string[]= [];
    const parts :string[]=path.split("/");
    for(let i:number=0;i<parts.length;i++){
        if(parts[i]==="." || parts[i]==="") continue;
        else if (parts[i]===".." && parts.length>0){
            stack.pop();
        }else {
            stack.push(parts[i]);
        }
    }
        return "/"+stack.join("/");
};