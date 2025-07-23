function minOperations(logs: string[]): number {
    let depth=0;
    for(const str of logs){
        if(str==="./"){
            continue;
        }else if(str==="../"){
            depth--;
        }else{
            depth++;
        }
    }
    return depth<0?0:depth ;
};